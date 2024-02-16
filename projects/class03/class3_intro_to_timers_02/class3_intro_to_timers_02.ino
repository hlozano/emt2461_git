/*		TIMERS MADE EASY BY HERNAN LOZANO  		*/

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
unsigned long LED1_timer = 0; // LED1_timer is incremented every 100ms = 0.1s
unsigned long LED2_timer = 0; // LED2_timer is incremented every 100ms = 0.1s
unsigned long LED3_timer = 0; // LED3_timer is incremented every 100ms = 0.1s
unsigned long debug_print_tmr = 0;
//review on data types
bool myboolvar = 0; // same as myboolvar= 0;

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
    Serial.begin(9600);  
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
	if(LED1_timer<5)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1_pin,HIGH); 
	else // greater or equal to 10
	{
		digitalWrite(LED1_pin,LOW);
		if(LED1_timer>=10) //(between 10 and 20 - another 1 s)
			LED1_timer = 0;	//When does the timer get cleared?
	}
}
void flash_LED2_pin()
{
	if(LED2_timer<20)			//Check timer and execute action 
		digitalWrite(LED2_pin,HIGH); 
	else
	{
		digitalWrite(LED2_pin,LOW);
		if(LED2_timer>=40)
			LED2_timer = 0;	//When does the timer get cleared?
	}
}
void flash_LED3_pin()
{
	if(LED3_timer<30)			//Check timer and execute action 
		digitalWrite(LED3_pin,HIGH); 
	else
	{
		digitalWrite(LED3_pin,LOW);
		if(LED3_timer>=60)
			LED3_timer = 0;	//When does the timer get cleared?
	}
}
void timers(void)
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	static unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 100s
		millis_old = millis_old + interval;
		LED1_timer++;
		LED2_timer++;
		LED3_timer++;
		debug_print_tmr++;
		//<---- Add new timer here		
	}
	if(millis_old > millis())
	{ //if you run for a very long time, correct overflow
		millis_old = millis();	
	}	
}
