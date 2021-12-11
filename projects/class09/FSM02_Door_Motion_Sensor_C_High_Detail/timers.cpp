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
		if(led_tmr <4000000000)
			led_tmr++;
		if(timer1 <4000000000)
			timer1++;
		if(sensor_tmr <4000000000)
			sensor_tmr++;
		if(debug_print_tmr <4000000000)
			debug_print_tmr++;
		if(sim_door_position_tmr <4000000000)
		   sim_door_position_tmr++;
	   	if(time_to_block > 0)
			time_to_block--;
		one_ms_timer = 0;
                
	}
}
