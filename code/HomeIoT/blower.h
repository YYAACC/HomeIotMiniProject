#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper step28BYJ48(stepsPerRevolution, 8,10,9,11);

void AllOff()
{
  step28BYJ48.step(0); 
}

void AirConditionerOn(int temp)
{
  step28BYJ48.step(stepsPerRevolution);
  Serial.print("temp :");
  Serial.print(temp);
  Serial.println("에어컨 On");
}

void AirConditionerOff(int temp)
{
  step28BYJ48.step(0);
  Serial.print("temp :");
  Serial.print(temp);
  Serial.println("에어컨 Off");
}

void AirConditionerOnOrOff(int temp,bool IO) //bool IO //밖에서 안으로 들어왔을때 ON,OFF
{
  if (temp >= 14 && IO == true ) // 온도가 14도 이상일 경우 모터ON( 에어컨 ).
  { 
    AirConditionerOn(temp);
  }
  else if(temp < 13 && IO == true)
  {
    AirConditionerOff(temp);
  }
  else if(IO ==false)
  {
    AllOff();
  }
  else step28BYJ48.step(0);
}

void HeaterOn(int temp)
{
  step28BYJ48.step(-stepsPerRevolution);
  Serial.print("temp :");
  Serial.print(temp);
  Serial.println("히터 On");
}
void HeaterOff(int temp)
{
  step28BYJ48.step(-stepsPerRevolution);
  Serial.print("temp :");
  Serial.print(temp);
  Serial.println("히터 Off");
}

void HeaterOnOrOff(int temp,bool IO) //bool IO //밖에서 안으로 들어왔을때 ON,OFF 
{
  if (temp  <= 5 && IO == false ) // 온도가 5도 이하일 경우 모터ON( 히터 ).
  {
    HeaterOn(temp);
  }
  else if(temp > 6 && IO == false) 
  {
    HeaterOff(temp);
  }else if(IO == true)
  {
    AllOff();  
  }
  else step28BYJ48.step(0);
}

void blowerInit(){
  step28BYJ48.setSpeed(10);
}
