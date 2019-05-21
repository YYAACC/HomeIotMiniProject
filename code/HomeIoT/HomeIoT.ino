#include "Buzzer.h"
#include <wiringSerial.h>

/*
#include "DoorLock.h"
#include "Camera.h"
#include "LED.h"
#include "DayOrNight.h"
#include "blower.h"
#include "cds.h"
#include "lcdCheck.h"
#include "temp.h"



int temp = 0;
int Illu = 0;
bool IO=true;     // In -> Out : true, Out -> In : false
char buffer;
*/

void setup() {  
  BuzzerInit();
  //DoorLockInit();  
  //CameraInit();
  //LEDInit();
  //DayOrNightInit();
  //blowerInit(); 
  //CDSInit();
  //lcdInit(); 
  //temperInit(); 
}
  
void loop() {   
  Key();
  Button();

  if(serialOpen("/dev/ttyAMA0",115200)<0){
    fprintf(stderr, "Unable to open serial device : %s \n", strerror(errno))
    return 1;
   }

  else
  
  //temp = temper();
  //Illu = CDS();

  if(

  lcdCheck(temp,Illu);

  DayOrNight(temp, Illu);
  LedOnOrOff(Illu);
  AirConditionerOnOrOff(temp,IO);
  HeaterOnOrOff(temp,IO);

  //serialClose();
      
}
