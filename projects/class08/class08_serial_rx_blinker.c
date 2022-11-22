/*		MCU # 2 		SLAVE			*/
//DEFINE ALL timer1 AS UNSIGNED AS VARIABLES	

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s


const int LED1 = 13;
int inByte;

void setup()
{               
   Serial.begin(9600); 
    pinMode(LED1, OUTPUT);      
}
void loop()
{
    static int command; 
    timers();
	if (Serial.available() > 0) 
	{
		inByte = Serial.read();
		command = inByte;
	}





	switch (command)
	{
		case '0': 
			flash_fast();
			break;
		case '1': 
			flash_led1s();
			break;
		case '2': 
			flash_led2s();
			break;
		case '3': 
			flash_led3s();
			break;
		case '4': 
			flash_led4s();
			break;
		case '5': 
			flash_led5s();
			break;
		default:
			command = 0;
			turn_off();
	}
}
void turn_off(void)
{
	digitalWrite(LED1,LOW);
}

void flash_fast()
{
	if(timer1<2)			
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=4) 
			timer1 = 0;	
	}
}

void flash_led1s() 
{
	if(timer1<5)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=10) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer1get cleared?
	}
}
void flash_led2s()
{
	if(timer1<10)			//Check timer1and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=20)
			timer1 = 0;	//When does the timer1get cleared?
	}
}
void flash_led3s()
{
	if(timer1<15)			//Check timer1and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=30)
			timer1 = 0;	//When does the timer1get cleared?
	}
}
void flash_led4s()
{
	if(timer1<20)			//Check timer1and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=40)
			timer1 = 0;	//When does the timer1get cleared?
	}
}
void flash_led5s()
{
	if(timer1<25)			//Check timer1and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=50)
			timer1 = 0;	//When does the timer1get cleared?
	}
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
		ms_runtime = millis();

	if(one_ms_timer> 99) // every 100 ms
	{
		timer1++;
		one_ms_timer= 0;
	}
}

