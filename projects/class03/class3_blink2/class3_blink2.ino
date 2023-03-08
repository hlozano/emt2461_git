unsigned long LED1_tmr; // LED1_tmr is incremented every 100ms = 0.1s (also 10 x 100ms = 1s)
//<---- Define new timer here

const int LED1 = 13;
// local functions
void timers(void);
void flash_led1(void);

void setup()
{                
    pinMode(LED1, OUTPUT);  
    Serial.begin(9600); 
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

void flash_led1_alternate_solution() 
{
	static bool led_status = 0;
	if(LED1_tmr>=10)
	{
		LED1_tmr = 0;
		led_status = !led_status;
		digitalWrite(LED1,led_status);
		Serial.println("Changing...");
	}
}

void timers(void)
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	static unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 100s
		millis_old = millis_old + interval;
		LED1_tmr++;
		//<---- Add new timer here
	}
	if(millis_old > millis())
	{ //if you run for a very long time, correct overflow
		millis_old = millis();	
	}	
}