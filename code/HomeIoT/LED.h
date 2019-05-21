#define LED 12

bool isLightOn=false;                                // true: On, false: Off

void LedOn(){
  digitalWrite(LED, HIGH);                           // Led On(정논리)
  isLightOn = true;
}

void LedOff(){
  digitalWrite(LED, LOW);                            // Led Off(정논리)
  isLightOn = false;
}

void LedOnOrOff(int Illuminance){          // 조명의 상태(LightState) 및 조도(Illuminance)에 따라 조명을 턴 온오프
  if(iLO==false && Illuminance < 600) LedOn();       // LED Off && 조도 < 600 -> LED On
  else if(iLO==true && Illuminance >=600) LedOff();  // LED Off && 조도 >= 600 -> LED Off
}

void LEDInit(){
  pinMode(LED, OUTPUT);
  LedOn();  
}
