/*		TIMERS MADE EASY BY HERNAN LOZANO  		*/
unsigned long ms_runtime = 0;
unsigned int one_ms_timer;
//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
unsigned long timer1 = 0; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2 = 0; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3 = 0; // timer3 is incremented every 100ms = 0.1s
unsigned long debug_print_tmr = 0;
//review on data types
bool myboolvar = FALSE; // same as myboolvar= 0;

void flash_LED1_pin(void);
void flash_LED2_pin(void);
void flash_LED3_pin(void);

const int LED1_pin = 11;
const int LED2_pin = 12;
const int LED3_pin = 13;

void setup()
{                
    pinMode(LED1_pin, OUTPUT);   
    pinMode(LED2_pin, OUTPUT);   
    pinMode(LED3_pin, OUTPUT);   
}
void loop()
{
    timers();
	flash_LED1_pin();
	flash_LED2_pin();
	flash_LED3_pin();
	debug_print();
}
void debug_print()
{
	if(debug_print_tmr >= 10) // remember serial_print_tmr increments every 0.1 sec (100ms)
	{	debug_print_tmr = 0;
		Serial.println("Still here");
	}
}
void flash_LED1_pin() 
{
	if(timer1<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1_pin,HIGH); 
	else // greater or equal to 10
	{
		digitalWrite(LED1_pin,LOW);
		if(timer1>=20) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer get cleared?
	}
}
void flash_LED2_pin()
{
	if(timer2<20)			//Check timer and execute action 
		digitalWrite(LED2_pin,HIGH); 
	else
	{
		digitalWrite(LED2_pin,LOW);
		if(timer2>=40)
			timer2 = 0;	//When does the timer get cleared?
	}
}
void flash_LED3_pin()
{
	if(timer3<39)			//Check timer and execute action 
		digitalWrite(LED3_pin,HIGH); 
	else
	{
		digitalWrite(LED3_pin,LOW);
		if(timer3>=78)
			timer3 = 0;	//When does the timer get cleared?
	}
}
void timers(void)
{
	int i;
	if(millis() > ms_runtime)
	{	//ms_runtime = ms_runtime + 1;
		ms_runtime++;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())// every 49 days we need to correct variable
	{// when ms_run time is 4,294,967,295 millis() will return 0
		ms_runtime = millis();
	}

	if(one_ms_timer > 99)
	{ // this runs every 100 ms
		timer1++;
		timer2++;
		timer3++;
		debug_print_tmr++;
		one_ms_timer = 0;
	}
}
/*
values for long variable
	ms				s			hr			days		weeks		months
	4,294,967,295	4294967.295	1193.046471	49.71026962	7.101467088	1.638800097
*/
