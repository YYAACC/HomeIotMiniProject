#include "Buzzer.h"
void Buzzer::BuzzerInit(){
  pinMode(BUZZER, OUTPUT);
  tone(BUZZER,1000,100);
  delay(200);
  tone(BUZZER,1000,100);
}

void Buzzer::BUZZ(){
  tone(BUZZER,523,100);   
}

void Buzzer::BUZZ_OPEN(){
  tone(BUZZER,523,100);
  delay(200);
  tone(BUZZER,659,100);
  delay(200);
  tone(BUZZER,783,100);
  delay(200);    
}

void Buzzer::BUZZ_CLOSE(){
  tone(BUZZER,783,100);
  delay(200);
  tone(BUZZER,659,100);
  delay(200);
  tone(BUZZER,523,100);
  delay(200);    
}

void Buzzer::BUZZ_WRONG(){
  tone(BUZZER,523,100);
  delay(200);
  tone(BUZZER,523,100);
  delay(200);
  tone(BUZZER,523,100);
  delay(200);   
}
