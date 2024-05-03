
//DEFINE ALL TIMERS AS UNSIGNED VARIABLES	
unsigned long timer1 = 0;        // timer1 increments every 100ms = 0.1s
unsigned long timeout_timer = 0; // timeout_timer increments every 100ms = 0.1s
unsigned long print_timer = 0;   // print_timer increments every 100ms = 0.1s

const int USER_LED_OUTPUT = 13;
const int USER_BUTTON_INPUT = 2;

void serial_debug(void);
void light_control(void);


void setup(void)
{ // initialize the digital pin as an output.               
	pinMode(USER_LED_OUTPUT, OUTPUT);     
	pinMode(USER_BUTTON_INPUT, INPUT);
	Serial.begin(9600);
}
void loop(void)
{	//run loop forever
	timers();
	light_control();
	serial_debug();
}

void serial_debug(void)
{
	if(print_timer>=5)
	{
		Serial.print(print_timer);
		Serial.print("    ");
		Serial.print(timer1);
		Serial.print("    ");
		Serial.println(timeout_timer);

		print_timer = 0;
	}
}

void light_control(void)
{
	static int state;
	static bool allow_change_of_state;

	if(digitalRead(USER_BUTTON_INPUT) == 0)
	{
		allow_change_of_state = 1;
	}

	if(state == 0)	
	{	if((allow_change_of_state == 1) && (digitalRead(USER_BUTTON_INPUT) == 1) )
		{	if(timer1 >= 5)
			{
				state = 1;
				allow_change_of_state = 0;
				timeout_timer = 0;
			}
		}
		else
		{
			timer1 = 0;
		}
	}
	else if(state == 1) 
	{
		if(timeout_timer > 200)
		{
			state = 0;
			timer1 = 0;
		}
	}	
	//execute commands based on state	
	if (state == 1)
		digitalWrite(USER_LED_OUTPUT, HIGH); 
	else if (state == 0)
		digitalWrite(USER_LED_OUTPUT, LOW);	
}

void timers(void)
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 100s
		millis_old = millis_old + interval;
		timer1++;
		timeout_timer++;
		print_timer++;
	}
	if(millis_old > millis())
	{ //if you run for a very long time, correct overflow
		millis_old = millis();	
	}		
}
