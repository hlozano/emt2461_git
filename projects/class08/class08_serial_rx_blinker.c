/*		TIMERS MADE EASY BY HERNAN LOZANO		*/
/*		MCU # 2 		SLAVE			*/
unsigned long ms_runtime;
int one_ms_timer;

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3; // timer3 is incremented every 100ms = 0.1s
unsigned long timer4; // timer4 is incremented every 100ms = 0.1s
unsigned long timer5; // timer5 is incremented every 100ms = 0.1s

const int LED1 = 13;
int inByte;
char mystring[] = " ";

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
/*                
				Serial.println(inByte);
                mystring[0] = (char)inByte;
                Serial.println(mystring[0]);*/ 
                //THIS CAN BE LEFT BEHIND BUT IT IS NOT NECESSARY
		command = inByte;
	}
	switch (command)
	{
		case '1': 
			flash_led1();
			break;
		case '2': 
			flash_led2();
			break;
		case '3': 
			flash_led3();
			break;
		case '4': 
			flash_led4();
			break;
		case '5': 
			flash_led5();
			break;
		default:
			turn_off();
	}
}
void turn_off(void)
{
	digitalWrite(LED1,LOW);
}
void flash_led1() 
{
	if(timer1<5)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=10) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer get cleared?
	}
}
void flash_led2()
{
	if(timer2<10)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer2>=20)
			timer2 = 0;	//When does the timer get cleared?
	}
}
void flash_led3()
{
	if(timer3<15)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer3>=30)
			timer3 = 0;	//When does the timer get cleared?
	}
}
void flash_led4()
{
	if(timer4<20)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer4>=40)
			timer4 = 0;	//When does the timer get cleared?
	}
}
void flash_led5()
{
	if(timer5<25)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer5>=50)
			timer5 = 0;	//When does the timer get cleared?
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
		timer1++;
		timer2++;
		timer3++;
		timer4++;
		timer5++;
		one_ms_timer = 0;
	}
}

