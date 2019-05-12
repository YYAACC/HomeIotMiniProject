#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = { 
  {'1','2','3','A'}, 
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'} 
  };

byte rowPins[4] = {6,7,8,9};
byte colPins[4] = {5,4,3,2};

Keypad keypad= Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

/* WITHOUT LIBRARY 
int KeyRow[4] = {6,7,8,9};
int KeyColumn[4] = {5,4,3,2};

int KeyCode[16] = {'1','2','3','A',
                   '4','5','6','B',
                   '7','8','9','C',
                   '*','0','#','D'};

void KeyInit(){
  for(int k=0;k<4;k++){
    pinMode(KeyRow[k], OUTPUT);
    digitalWrite(KeyRow[k],HIGH);
    pinMode(KeyColumn[k], INPUT_PULLUP);
  } 
}

int KeyScan(){
  int nRow, nNumber=-1;
  int KC=-1;
  
  for (int k=0;k<4;k++){
    digitalWrite(KeyRow[k], LOW);
    nRow = k*4;
    for (int m=0;m<4;m++){
      if(!digitalRead(KeyColumn[m])){
        nNumber = nRow+m;               
      }
    }
    digitalWrite(KeyRow[k],HIGH);    
    delay(20);  
  } 
  if(nNumber>=0){
    KC = KeyCode[nNumber];
  }  
  return KC;
}

void KeyPrint(signed int KeyValue){
  Serial.print("KEY[");
  Serial.print((char)KeyCode[KeyValue]);
  Serial.println("] PUSH");
}*/
