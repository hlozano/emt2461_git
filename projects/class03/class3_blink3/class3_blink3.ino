/*		TIMERS MADE EASY BY HERNAN LOZANO		*/

unsigned long ms_runtime;
int one_ms_timer;

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3; // timer3 is incremented every 100ms = 0.1s

void flash_led1();
void flash_led2();
void flash_led3();

long int myvar1 = 0;
long int myvar2 = 0;
long int myvar3 = 0;
long int myvar4 = 0;
long int myvar5 = 0;
long int myvar6 = 0;
long int myvar7 = 0;


const int LED1 = 11;
const int LED2 = 12;
const int LED3 = 13;

void setup()
{                
    pinMode(LED1, OUTPUT);   
    pinMode(LED2, OUTPUT);   
    pinMode(LED3, OUTPUT);   

}
void loop()
{
    timers();
	flash_led1();
	flash_led2();
	flash_led3();
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
void flash_led2()
{
	if(timer2<15)			//Check timer and execute action 
		digitalWrite(LED2,HIGH); 
	else
	{
		digitalWrite(LED2,LOW);
		if(timer2>=30)
			timer2 = 0;	//When does the timer get cleared?
	}
}
void flash_led3()
{
	if(timer3<50)			//Check timer and execute action 
		digitalWrite(LED3,HIGH); 
	else
	{
		digitalWrite(LED3,LOW);
		if(timer3>=100)
			timer3 = 0;	//When does the timer get cleared?
	}
}

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
		if(timer1 <4000000000)
		{
			timer1++;
			timer2++;
			timer3++;
		}
		one_ms_timer = 0;
	}
}

