#include <Arduino.h>

unsigned long ms_runtime = 0;
unsigned int one_ms_timer = 0;
unsigned long timer1 = 0; // timer1 is incremented every 100ms = 0.1s
unsigned long led_tmr = 0; // timer1 is incremented every 100ms = 0.1s

void timers(void)
{
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
		led_tmr++;
		timer1++;
		one_ms_timer = 0;
	}
}
