#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
  const int BUZZER_P=13

  public:
  void BuzzerInit();

  void BUZZ();  
  void BUZZ_OPEN();  
  void BUZZ_CLOSE();  
  void BUZZ_WRONG();
}

#endif
