/*
 * 스텝 모터를 통해 문의 잠금장치를 구동하기 위한 코드를 포함하고 있습니다.
 */

#include <Stepper.h>

#define INT1 A0
#define INT2 A1
#define INT3 A2
#define INT4 A3

bool InOrOut=true;                       // In -> Out : true, Out -> In : false

const int stepsPerRevolution = 2048;
Stepper step28BYJ48(stepsPerRevolution, INT1, INT3, INT2, INT4);

void Open(){                              
  Serial.println("문이 열립니다!");   
  step28BYJ48.step(stepsPerRevolution/4); // 문이 열림: 모터 정방향(반시계) 회전
  delay(500);
}

bool OpenFromOutside(){                   // 밖에서 안으로 들어오기 위해 문이 열림.
  Open();
  InOrOut=false;                          // Out -> In : false
  return InOrOut;
}

bool OpenFromInside(){                    // 안에서 밖으로 들어오기 위해 문이 열림.
  Open();
  InOrOut=true;                           // In -> Out : true
  return InOrOut;
}

void Close(){                              // 문이 닫힘.             
  Serial.println("문이 닫힙니다!");   
  step28BYJ48.step(-stepsPerRevolution/4); // 문이 닫힘: 모터 역방향(시계) 회전
  delay(500);
}

void DoorInit(){                            // 문(스텝 모터) 초기화: 닫힌 상태
  step28BYJ48.setSpeed(10);
  Close();
}

/*
#include <Servo.h>
#define ServoMotor 11

Servo servo;

void Close(){              //90도->0도  
  Serial.println("문이 닫힙니다!");   
  for(int k=90;k>0;k--){
    servo.write(k);
    delay(15);
  } 
}

void Open(){              //0도->90도
  Serial.println("문이 열립니다!");
  for(int k=0;k<90;k++){
    servo.write(k);
    delay(15);
  }
}

void DoorInit(){
  servo.attach(ServoMotor);
  Close();
}
*/
