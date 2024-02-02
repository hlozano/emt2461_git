unsigned long button_dbnc_tmr;	// button_dbnc_tmr is incremented every 100ms = 0.1s
unsigned long blinking_tmr;		// blinking_tmr is incremented every 100ms = 0.1s
unsigned long delay_blink_tmr;	// delay_blink_tmr is incremented every 100ms = 0.1s


//<---- Define new timer here

void timers(void);
/* timers() 
	we started this program under the assumption that we will hide (or pretend to
	hide) the details of the implementation of timers. Here we just count on the
	fact that just by adding button_dbnc_tmr++ in the right location, it will increment
	every 100 ms. How? At this point, do not worry! next week you will :)
*/
const int LED1_pin = 13;
const int buttonPin = 2;

void setup()
{  // initialize the digital pin as an output.
	pinMode(LED1_pin, OUTPUT);     
}
void loop()
{
	timers();
	if(delay_blink_tmr >= 50)
	{//delay first reaction by 5 seconds
		//THEN blink 1 sec on and 1 sec off
		if(blinking_tmr < 10) // [0,1,2,3,4,5,6,7,8,9] -> 10 times 100 ms (ten iterations of 100ms = 1 sec)
			digitalWrite(LED1_pin, HIGH); 
		else if (blinking_tmr < 20)
			digitalWrite(LED1_pin, LOW);
		else
			blinking_tmr = 0;
	}
	else
	{
		blinking_tmr = 0;
	}
}

void timers(void)
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	static unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 100s
		millis_old = millis_old + interval;
		button_dbnc_tmr++;
		blinking_tmr++;
		delay_blink_tmr++;
		//<---- Add new timer here
	}   
	if(millis_old > millis())
	{ //if you run for a very long time, correct overflow
		millis_old = millis();	
	}		
}
