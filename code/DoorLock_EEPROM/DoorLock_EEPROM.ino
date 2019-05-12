#include "Buzzer.h"
#include "Door.h"
#include "Key.h"
#include "Password.h"

void setup() {
  // put your setup code here, to run once:
  
  LEDInit();  
  BuzzerInit();  
  DoorInit();
  PasswordInit();
  
  Serial.begin(9600);   
}
  
void loop() {
  // put your main code here, to run repeatedly:
  
  char KeyValue = keypad.getKey();    // 키패드로부터 입력받음.
    
  if(KeyValue){
    BUZZ();         
    WhichMode(KeyValue);
  }

  //LedOnOff(int Illuminance)

   
}
