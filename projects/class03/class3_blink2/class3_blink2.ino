/*		TIMERS MADE EASY BY HERNAN LOZANO		*/

unsigned long ms_runtime;
int one_ms_timer;

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s

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
	if(timer1<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=20) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer get cleared?
	}
}
void timers(void)
{
	
	if(millis() > ms_runtime)
	{
		ms_runtime++;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
		ms_runtime = millis();
	//better aapproach
	//else if( ms_runtime > millis())
	//{
	//	ms_runtime = millis();
	//	one_ms_timer++;
	//}
	if(one_ms_timer > 99)
	{
		timer1++;
		one_ms_timer = 0;
	}
}
