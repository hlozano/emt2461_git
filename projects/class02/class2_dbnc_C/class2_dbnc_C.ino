unsigned long ms_runtime;
int one_ms_timer;

unsigned long button_dbnc_tmr; // button_dbnc_tmr is incremented every 100ms = 0.1s
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
	pinMode(buttonPin, INPUT);
}
void loop()
{
    timers();
	if(digitalRead(buttonPin) == 1) 
	{  // 10 times 0.100 s( 100ms) = 1 second
		if(button_dbnc_tmr >= 10) // [0,1,2,3,4,5,6,7,8,9] -> 10 times 100 ms (ten iterations of 100ms = 1 sec)
			digitalWrite(LED1_pin, HIGH); 
	}
	else
	{
		digitalWrite(LED1_pin, LOW);
		button_dbnc_tmr = 0;		// clear timer (RESETTING THE TIEMR TO ZERO)
	} 
}
/*
	Opposite to what happened in the previous version of this program, here the
	length of loop time will not have any repercussion on the time of the debounce.
	The loop time will have to go beyond a 1ms average before the performance of this program is affected.
*/
void timers(void)
{
	if(millis() > ms_runtime)
	{
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99) // one_ms_tmr .. 0,1,2,3,4,5....99,0
	{//come in here every 100 ms
		button_dbnc_tmr++;
		//<---- Add new timer here
		one_ms_timer = 0;
	}
}
