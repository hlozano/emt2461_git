
//DEFINE ALL TIMERS AS UNSIGNED VARIABLES	
unsigned long timer1 = 0; // timer1 increments every 100ms = 0.1s
const int USER_LED_OUTPUT = 13;
const int USER_BUTTON1_INPUT = 2;
const int USER_BUTTON2_INPUT = 3;
void setup()
{ // initialize the digital pin as an output.               
	pinMode(USER_LED_OUTPUT, OUTPUT);     
	pinMode(USER_BUTTON1_INPUT, INPUT);
	Serial.begin(9600);
}
void loop()
{	//run loop forever
	static int state;
	static bool allow_change_of_state;
	timers();
	

	if(button_pressed() == 0)
	{
		allow_change_of_state = 1;
	}

	if(state == 0)	
	{	if((allow_change_of_state == 1) && (button_pressed() == 1) )
		{
			state = 1;	
			allow_change_of_state = 0;
		}
	}
	else if(state == 1) 
	{	if((allow_change_of_state == 1) && (button_pressed() == 1)) 
		{	
			state = 0;
			allow_change_of_state = 0;
		}
	}
	//execute commands based on state	
	if (state == 1)
		digitalWrite(USER_LED_OUTPUT, HIGH); 
	else if (state == 0)
		digitalWrite(USER_LED_OUTPUT, LOW);

}

int button_pressed(void)
{
	int result = 0;
	if((digitalRead(USER_BUTTON1_INPUT) == 1) || (digitalRead(USER_BUTTON2_INPUT) == 1))
	{
		if(timer1 >= 5)
			result=1;
	}
	else
	{
		timer1 = 0;
	}

	return result;

} 

void timers(void)
{
	static unsigned long ms_runtime;
	static int one_ms_timer;
	if(millis() > (ms_runtime + 1))
	{	ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
		ms_runtime = millis();
	if(one_ms_timer > 99)
	{	timer1++;
		one_ms_timer = 0;
	}
}



