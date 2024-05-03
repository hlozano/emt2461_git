/*		TIMERS MADE EASY BY HERNAN LOZANO		*/
//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3; // timer3 is incremented every 100ms = 0.1s
unsigned long timer99; // timer99 is decremented every 100ms = 0.1s


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
	flash_led1();//task01
	flash_led2();//task02
	flash_led3();//task03
}


void flash_led1() 
{
	if(timer1<1)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else if(timer1 <2)
		digitalWrite(LED1,LOW);
	else
		timer1 = 0;

}
void flash_led2()
{
	if(timer2<15)			//Check timer and execute action 
		digitalWrite(LED2,HIGH); 
	else if (timer2 < 30)
		digitalWrite(LED2,LOW);
	else
		timer2 = 0;
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
	static unsigned long previousMillis = 0;// track the # ms the mcu has been running
	static unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= previousMillis + interval)
	{//it falls into this section once every 100s
		previousMillis = previousMillis + interval;
		timer1++;
		timer2++;
		timer3++;
		if(timer99>0)
			timer99--;
		//<---- Add new timer here		
	}
	if(previousMillis > millis())
	{ //if you run for a very long time, correct overflow
		previousMillis = millis();	
	}	
}
