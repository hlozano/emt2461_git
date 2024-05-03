#import <Arduino.h>
#include "doorlimits.h"

unsigned long timer1 = 0; // timer1 is incremented every 100ms = 0.1s
unsigned long led_tmr = 0;
unsigned long sensor_tmr = 0;
unsigned long time_to_block = 0;
unsigned long debug_print_tmr = 0;
unsigned long sim_door_position_tmr = 0;

void timers(void);


 void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
	millis_old = millis_old + interval;
	led_tmr++;
	timer1++;
	sensor_tmr++;
	debug_print_tmr++;
	sim_door_position_tmr++;
	if(time_to_block > 0)
		time_to_block--;	
  }
  if(millis_old > millis())
  { //if you run for a very long time, correct overflow
    millis_old = millis();  
  }   
}


void timers(void)
{
	static unsigned long ms_runtime = 0;
	static unsigned int one_ms_timer = 0;
	int i;

	if(millis() > (ms_runtime + 1))
	{
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  

	}
	else if( ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99) // every 100 ms
	{

		one_ms_timer = 0;
                
	}
}
