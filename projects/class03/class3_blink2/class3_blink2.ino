/*		TIMERS MADE EASY BY HERNAN LOZANO		*/
//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
unsigned long LED1_tmr; // LED1_tmr is incremented every 100ms = 0.1s (also 10 x 100ms = 1s)
const int LED1 = 13;
// local functions
void timers(void);
void flash_led1(void);

void setup()
{                
    pinMode(LED1, OUTPUT);   
}
void loop()
{
    timers();
	flash_led1();
}
void flash_led1() 
{
	if(LED1_tmr<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else if(LED1_tmr < 20) 
		digitalWrite(LED1,LOW);
	else
		LED1_tmr = 0;	//When does the timer get cleared?
}
void timers(void)
{
	static unsigned long ms_runtime;
	static int one_ms_timer;
	if(millis() > ms_runtime)
	{
		ms_runtime++;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
	{
		ms_runtime = millis();
		one_ms_timer++;
	}

	if(one_ms_timer > 99)
	{//increment all user defined timer variables
		LED1_tmr++;
		one_ms_timer = 0;
	}
}
