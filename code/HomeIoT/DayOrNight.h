#include <Stepper.h>
const int stepsPerRevolution =2048;
Stepper stepbb(stepsPerRevolution,8,10,9,11);

int flag=0;

void day(int temp){
  
  if(temp>15 && flag==0)      //flag =0 : 커튼 열려있음
   {
    stepbb.step(stepsPerRevolution);
    flag=1;
    Serial.println(" 여름 낮이고 커튼 닫힘");
   } //온도가 15도 초과이고 커튼이 열려있을때 커튼 닫힘
   if(temp<=15 && flag==1)    //flag = 1 : 커튼 닫혀있음.  //O
   {
    stepbb.step(stepsPerRevolution);
    flag=0;
    Serial.println(" 겨울 낮이고 커튼 열림");
   } //온도가 15도 이하이고 커튼이 닫혀있을때 커튼 열림 
}

void night(int temp){
  
    if(temp>15 && flag==0)
    {
      stepbb.step(stepsPerRevolution);
      flag=1;
      Serial.println(" 여름 밤이고 커튼 닫힘");
    } //온도가 15도 초과이고 커튼이 열려있을때 커튼 닫힘
    else if(temp<=15 && flag==0)
    {
      stepbb.step(stepsPerRevolution);
      flag=1;
      Serial.println("겨울 밤이고 커튼 닫힘");
    } //온도가 15도 이하이고 커튼이 닫혀있을때 커튼 닫힘
  
}
void DayOrNight(int temp, int Illumi)
{  
 if(Illumi>700) day(temp); //조도가 700이상이면 낮
 else night(temp); //아닐때 밤
}

void DayOrNightInit(){      // 커튼 초기화
  stepbb.setSpeed(10);
}
