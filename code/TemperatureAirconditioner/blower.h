#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper step28BYJ48(stepsPerRevolution, 8,10,9,11);

void blowerOnOFF(int temp)//bool IO //밖에서 안으로 들어왔을때 ON,OFF
{  
  if (temp >= 14 ) // 온도가 14도 이상일 경우 팬ON(정방향(시계반대) -에어컨 ).
  {
    step28BYJ48.step(stepsPerRevolution);
    Serial.println("에어컨 ON");
  }                 
  else if (temp < 5 ) // 온도가 5도 미만일 경우 팬ON(역방향(시계방향) - 히터).
  {        
    step28BYJ48.step(-stepsPerRevolution);
    Serial.println("히터 ON");
  }
   else 
   {       
     step28BYJ48.step(stepsPerRevolution/2048);
     Serial.println("에어컨,히터 OFF ");    
   } 
}

void blowerOFF() //안에서 밖으로 나갔을때 OFF
{
    step28BYJ48.step(stepsPerRevolution/2048);  
    Serial.println("에어컨,히터 OFF");
}
/*  
void IO(bool IO)
{
  if(IO == true) //안에서 밖으로 나갔을때
  {
    blowerOFF();  
  }
  else
  {
    blowerOnOFF(); //밖에서 안으로 들어왔을때
  }
}*/

int InputTemperature(){
  Serial.println(Serial.parseInt());
}
  
