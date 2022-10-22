
//DEFINE ALL TIMERS AS UNSIGNED VARIABLES	
unsigned long timer1 = 0; // timer1 increments every 100ms = 0.1s
unsigned long print_timer = 0; // timer1 increments every 100ms = 0.1s

const int USER_LED_OUTPUT = 13;
const int USER_BUTTON1_INPUT = 2;
const int USER_BUTTON2_INPUT = 3;

void serial_debug(void);
void light_control(void);
int button_pressed(void);


void setup()
{ // initialize the digital pin as an output.               
	pinMode(USER_LED_OUTPUT, OUTPUT);     
	pinMode(USER_BUTTON1_INPUT, INPUT);
	Serial.begin(9600);
}
void loop()
{	//run loop forever

	timers();
	light_control();
	serial_debug();
}

void light_control(void)
{
	static int state;
	static bool allow_change_of_state;
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


void light_control_version2(void)
{
	static int state;
	static int button_pressed_previous;
	static int button_rising_trigger;

	button_rising_trigger = (button_pressed_previous == 0) && 
							(button_pressed() == 1) ;

	if(state == 0)	
	{	if(button_rising_trigger)
		{
			state = 1;	
		}
	}
	else if(state == 1) 
	{	if(button_rising_trigger) 
		{	
			state = 0;
		}
	}
	button_pressed_previous = button_pressed();

	//execute commands based on state	
	if (state == 1)
		digitalWrite(USER_LED_OUTPUT, HIGH); 
	else if (state == 0)
		digitalWrite(USER_LED_OUTPUT, LOW);	
}

void serial_debug(void)
{
	if(print_timer >= 5)	
	{
		// Serial.print(print_timer);
		// Serial.print("    ");
		Serial.println(timer1);
		// Serial.print("    ");
		// Serial.println(timeout_timer);	
		print_timer = 0;
	}
}

int button_pressed(void)
{
	int result = 0;
	if((digitalRead(USER_BUTTON1_INPUT) == 1) || 
	   (digitalRead(USER_BUTTON2_INPUT) == 1))
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
		print_timer++;
		one_ms_timer = 0;
	}
}



