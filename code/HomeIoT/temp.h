#include <DHT.h>

#define DHT_pin 3
#define DHTTYPE DHT11
DHT dht11(DHT_pin,DHTTYPE);

int temper()//온도 측정
{ 
  int temp = dht11.readTemperature();
  return temp ;
}

void temperInit(){
  //pinMode()
}
