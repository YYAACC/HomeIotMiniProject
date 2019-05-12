#include <DHT.h>

#define DHT_pin 3
#define DHTTYPE DHT11
DHT dht11(DHT_pin,DHTTYPE);

int temp;

void InitTemp(){
  pinMode(DHT_pin, INPUT);  
}

int temper()//온도 측정
 {  
  if(Serial.available())
  {
    temp = InputTemperature();    
  }
  return temp;
  /*
    int temp = dht11.readTemperature();
    Serial.print("temp :");
    Serial.print(temp);
    return temp;
*/
 }
