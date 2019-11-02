#ifndef TimerDef
	#define TimerDef
	
	extern unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
	extern unsigned long led_tmr;
	extern unsigned long sensor_tmr;
	extern unsigned long time_to_block;
	extern unsigned long debug_print_tmr;
	extern unsigned long sim_door_position_tmr;


	extern void timers(void);
	
	
	
#endif