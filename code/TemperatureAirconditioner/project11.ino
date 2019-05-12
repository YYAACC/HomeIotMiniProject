#include "blower.h"
#include "temp.h"

void setup( ) {
  
  step28BYJ48.setSpeed(15);
  InitTemp();
  Serial.begin(9600);
}
void loop( )
{ 
 // delay(1000); //Wait a few seconds 
 int t = temper();
 Serial.println(t);
  blowerOnOFF(t); 
}
/*나갈떄 )
blowerOFF(BUTTONCLOSE())
BUTTONCLOSE()
*/
/*#include <Stepper.h>


float sensor = 0;
float voltage = 0;
float celsius = 0;


const int stepsPerRevolution = 2048;
Stepper step28BYJ48(stepsPerRevolution, 8,10,9,11);




void setup() {
        step28BYJ48.setSpeed(3);
        Serial.begin(9600);

}
  
void loop() {
        // 센서로 부터 자료값을 받음.
        sensor = analogRead(A0); 
        float voltage = sensor * 5000.0/1024.0;     // 온도센서의 값을 전압으로 변환
        float celsius = (voltage - 500) / 10.0;



        delay(1000); //Wait a few seconds
        
        

        Serial.print("temp :");
        Serial.println(celsius);
        
        /*
        // 온도가 28도 이상일 경우 ON(정방향 - 냉방)
        if (temp >= 28 ) {
            step28BYJ48.step(stepsPerRevolution);
            //delay(500); 
        } 
                // 온도가 20도 미만일 경우 팬ON(역방향 - 히터).
        else if (temp < 20 ) {
            step28BYJ48.step(-stepsPerRevolution);
            //delay(500); 
        }
        else  {
          
            step28BYJ48.step(0);
            //delay(500);

        } 
  

   
       } */
