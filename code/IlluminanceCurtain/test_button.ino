#include <Stepper.h>
const int stepsPerRevolution =2048;
Stepper stepbb(stepsPerRevolution,8,10,9,11);

int ledPin = 4;
int buttonApin=6;
int buttonBpin=5;
#define cds A2

byte leds=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(buttonApin,INPUT_PULLUP);
  pinMode(buttonBpin,INPUT_PULLUP);
 // pinMode(cds,INPUT);
  stepbb.setSpeed(15);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  button();
 // motor();
  cdsLED();
 

}
void button(){
  if(digitalRead(buttonApin) ==LOW) //9
  {
    digitalWrite(ledPin,HIGH); 
    Serial.println("Clockwise");
    stepbb.step(stepsPerRevolution);
    delay(500);
  }
  
  if(digitalRead(buttonBpin) ==LOW) //8
  {
    digitalWrite(ledPin,LOW);
    Serial.println("counterClockwise");
    stepbb.step(-stepsPerRevolution);
    delay(500);
  }
}

/*void motor(){
  Serial.println("Clockwise");
  stepbb.step(stepsPerRevolution);
  delay(500);

  Serial.println("counterClockwise");
  stepbb.step(-stepsPerRevolution);
  delay(500);
}*/
void cdsLED(){
  int val=analogRead(cds);
  Serial.println(String(val));
  delay(1000);

  if(val>=170){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}
