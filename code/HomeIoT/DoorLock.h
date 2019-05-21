/*
 * DoorLock에 대한 코드입니다. * 
 * 1) 문의 잠금장치를 위한 Stepper,
 * 2) 비밀번호를 설정 및 확인하는 Password,
 * 3) 내부에서 문을 열기 위한 Button
 * 4) 비밀번호를 입력하기 위한 Keypad,
 */
  
/*
 * 1) Stepper: Variable
 */
#include <Stepper.h>
#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3
const int stepsPerRevolution = 2048;
Stepper step28BYJ48(stepsPerRevolution, IN1, IN3, IN2, IN4);
bool InOrOut=true;                       // In -> Out : true, Out -> In : false
bool OpenOrCloseDoor=false;

/*
 *  2) Password: Variable
 */
#include <EEPROM.h>
const unsigned int Address = 100;        // 500~503 : 비밀번호 저장 번지
bool KeypadMode;      //true: 비밀번호 입력, false: 비밀번호 설정
byte star_Count=0;
char pushed_PWD[5] = {' ',' ',' ',' ',' '};
byte WrongCount=0;

/*
 *  3) Button: Variable
 */
#define OpenButton 11

/*
 * 4) Keypad: Variable
 */
#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = { 
  {'1','2','3','A'}, 
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'} 
  };
byte rowPins[4] = {6,7,8,9};
byte colPins[4] = {5,4,3,2};
Keypad keypad= Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

/*
 * 1) Stepper: Function
 */

void Close(){ 
 if(!OpenOrCloseDoor){                              // 잠금 장치가 걸려있으면,
   BUZZ_CLOSE();
   Serial.println("이미 문이 잠겨 있습니다!");         // 잠금 장치 걸린 상태 유지                                  
   delay(500);                                              
 }
 else{                                              // 잠금 장치가 해제되어 있으면,
   step28BYJ48.step(-stepsPerRevolution/4);         // 잠금 장치 걸림: 모터 역방향(시계) 회전
   Serial.println("문이 닫힙니다!");       
   OpenOrCloseDoor = false;
   BUZZ_CLOSE();
   delay(500);
 }  
}

void Open(){
  unsigned long Past=0;
  if(!OpenOrCloseDoor){                             // 잠금 장치가 걸려있으면,
    step28BYJ48.step(stepsPerRevolution/4);         // 잠금 장치 해제: 모터 정방향(반시계) 회전
    BUZZ_OPEN();
    Serial.println("문이 열립니다!");
    OpenOrCloseDoor = true;
    Past = millis();
    Serial.print(Past);
    Serial.print("    ");
    Serial.println(millis());    
    while(millis()-Past<10000){
      Serial.print(Past);
    Serial.print("    ");
    Serial.println(millis());   
    }                      // 잠금장치가 해제된 후 10초 후에 잠금장치 잠김   
    Close();                                       
  }
  else{                                             // 잠금 장치가 해제되어 있으면,
    BUZZ_WRONG();
    Serial.println("이미 문이 열려 있습니다!");        // 잠금 장치 해제 상태 유지 
  }  
}

bool OpenFromOutside(){                   // 밖에서 안으로 들어오기 위해 문이 열림.
  Serial.print("밖에서 안으로 ");
  Open();                            
  return false;                           // Out -> In : false -> InOrOut
}

bool OpenFromInside(){                    // 안에서 밖으로 들어오기 위해 문이 열림.
  Serial.print("안에서 밖으로 ");
  Open();
  return true;                            // In -> Out : true -> InOrOut  
}

void DoorInit(){                          // 잠금 장치(스텝 모터) 초기화: 닫힌 상태
  step28BYJ48.setSpeed(10);  
  Close();
}

/*
 *  2) Password
 */
 
void ShowResult(bool chk){
  if(chk)
  {
    pushed_PWD[3] = '*';    
    Serial.println("비밀번호가 일치합니다!");
    WrongCount=0;
    InOrOut = OpenFromOutside();                
  }
  else{ 
    BUZZ_WRONG();
    Serial.println("비밀번호가 일치하지 않습니다!");
    /*
     * if(++Wrongcount>3)  사진 전송
     */        
  }
}

bool CheckOutPWD(){  
  for(int k=0;k<4;k++){    
    if(pushed_PWD[k] != EEPROM.read(Address+k)){      
      return false;
    }   
  }  
  return true;
}

void SetPassword(char KeyValue){
  switch(KeyValue){
      case 'A':        
      case 'B':        
      case 'C':
      case 'D':
      case '*': 
      break;
      case '#':         
        KeypadMode=true; 
        Serial.println("");
        for(int k=Address;k<Address+4;k++){   // 설정된 비밀번호를 EEPROM에 저장          
          EEPROM.write(k,pushed_PWD[k-Address]);
        }    
        
        Serial.println("");               
        Serial.println("비밀번호가 설정 되었습니다");
        Serial.print("입력한 비밀번호 : ");
        break;      
      default:      
      { 
        pushed_PWD[4] = KeyValue; 
        Serial.print(pushed_PWD[4]);     
        
        for(int k=1;k<5;k++){
          pushed_PWD[k-1] = pushed_PWD[k];                    
        }                       
      }      
    }
}

void InputPassword(char KeyValue)
{
  switch(KeyValue){
    case 'C':
    case 'D':
      break;
    case 'A':
      Close();    
      break;  
    case 'B':
      //Open();
      break;
    case '#':
      ShowResult(CheckOutPWD());         
      break;
    case '*':        
      if(++star_Count==4)       // ****을 누르면 비밀번호 설정 모드로 전환
      {
        KeypadMode=false;
        star_Count=0;                
        Serial.println("비밀번호 설정 모드입니다");
        for(int k=0;k<5;k++){
          pushed_PWD[k] =' ';
        }            
        Serial.print("설정할 비밀번호 : ");           
      }
      break;
    default:      
    { 
      pushed_PWD[4] = KeyValue;
      Serial.print(pushed_PWD[4]);
     
      for(int k=1;k<5;k++){
        pushed_PWD[k-1] = pushed_PWD[k];               
      }   
    }      
  }            
}

void WhichMode(char KV){ 
  if(KeypadMode) InputPassword(KV);
  else SetPassword(KV);
}

/*
 *  3) Button: Function
 */
 void ButtonInit(){
  pinMode(OpenButton, INPUT_PULLUP);  
}

bool Button(){  
  if(!digitalRead(OpenButton)){
    BUZZ();
    Serial.print("버튼 클릭/");
    InOrOut = OpenFromInside();      
  }
}

/*
 * 4) Keypad: Function
 */
void Key(){
  char KeyValue = keypad.getKey();    // 키패드로부터 입력받음.
  if(KeyValue){    
    Serial.println(KeyValue);
    BUZZ();         
    WhichMode(KeyValue);
  }    
}

/*
 * Total: Function
 */
 void DoorLockInit(){
  DoorInit();
  ButtonInit();
  KeypadMode=true;
}
