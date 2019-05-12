#include <EEPROM.h>

const byte Address = 1000;
bool Mode=true;      //true: 비밀번호 입력, false: 비밀번호 설정
signed int star_Count=0;

char PWD[5] = {'1','0','3','3','#'};
char pushed_PWD[5] = {' ',' ',' ',' ',' '};

signed int WrongCount=0;

void PasswordInit(){
  for(int k=Address;k<Address+4;k++){    
    PWD[k-Address] = (char)EEPROM.read(k);    
  } 
}

void ShowResult(bool chk){
  if(chk)
  {
    pushed_PWD[3] = '*';    
    Serial.println("비밀번호가 일치합니다!");
    WrongCount=0;
    BUZZ_RIGHT();  
    Open();                
  }
  else{ 
    BUZZ_WRONG();
    Serial.println("비밀번호가 일치하지 않습니다!");
    /*
     * if(++Wrongcount>3)  사진 전송
     */        
  }
}

bool CheckOutPWD(char p_PWD[]){  
  for(int k=0;k<4;k++){    
    if(PWD[k] != p_PWD[k]){      
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
        Mode=true; 
        Serial.println("");
        for(int k=Address;k<Address+4;k++){   // 설정된 비밀번호를 EEPROM에 저장
          EEPROM.write(k,PWD[k-Address]);
          Serial.println((char)EEPROM.read(k));
        }    
        
        Serial.println("");               
        Serial.println("비밀번호가 설정 되었습니다");
        //Serial.println("비밀번호 입력 모드입니다");
        Serial.print("입력한 비밀번호 : ");
        break;      
      default:      
      { 
        PWD[4] = KeyValue; 
        Serial.print(PWD[4]);     
        
        for(int k=1;k<5;k++){
          PWD[k-1] = PWD[k];          
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
      Open();
      break;
    case '#':
      ShowResult(CheckOutPWD(pushed_PWD));         
      break;
    case '*':        
      if(++star_Count==4)       // ****을 누르면 비밀번호 설정 모드로 전환
      {
        Mode=false;
        star_Count=0;                
        Serial.println("비밀번호 설정 모드입니다");
        for(int k=0;k<5;k++){
          PWD[k] =' ';
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
  if(Mode) InputPassword(KV);
  else SetPassword(KV);
}
