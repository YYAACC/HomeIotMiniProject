#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
unsigned long prev_time1 = 0;

void lcdCheck(int temp,int val){
  unsigned long current_time1=millis();

  if(current_time1 - prev_time1>1000){   
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("NOW CDS IS = ");
    lcd.print(val);
    lcd.setCursor(0,1);
    lcd.print("NOW TEMP IS = ");
    lcd.print(temp);
    prev_time1=current_time1;
  }  
}

void lcdInit(){
  lcd.begin();
}
