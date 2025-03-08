#include <Arduino.h>

unsigned long timer1 = 0; // timer1 is incremented every 100ms = 0.1s
unsigned long led_tmr = 0; // timer1 is incremented every 100ms = 0.1s

void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
    millis_old = millis_old + interval;
	led_tmr++;
	timer1++;
  }
  if(millis_old > millis())
  { //if you run for a very long time, correct overflow
    millis_old = millis();  
  }   
}



