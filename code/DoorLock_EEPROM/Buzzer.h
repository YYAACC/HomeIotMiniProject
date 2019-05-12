#define BUZZER 13

void BuzzerInit(){
  pinMode(BUZZER, OUTPUT);
  tone(BUZZER,1000,100);
  delay(200);
  tone(BUZZER,1000,100);
}

void BUZZ(){
  tone(BUZZER,523,100);   
}

void BUZZ_RIGHT(){
  tone(BUZZER,523,100);
  delay(200);
  tone(BUZZER,659,100);
  delay(200);
  tone(BUZZER,783,100);
  delay(200);    
}

void BUZZ_WRONG(){
  tone(BUZZER,523,100);
  delay(200);
  tone(BUZZER,523,100);
  delay(200);
  tone(BUZZER,523,100);
  delay(200);   
}
