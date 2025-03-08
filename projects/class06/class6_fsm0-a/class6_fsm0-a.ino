/*variables required for timers() to work*/
/*this program turns output on when button is pressed*/
/*then it times out and turns off after one hour*/


int light_state;
//light_state = 0 -> light is off
//light_state = 1 -> light is on 
int button_pin = 11;
int light_pin = 12;
int heart_beat_pin = 13;

void timers(void);
void heartbeat_control(void);
void light_control(void);
int button_pressed(void);
int turn_light_on(void);
int turn_light_off(void);

unsigned int timer1 = 0;	//used for debouncing input
unsigned int light_timeout_timer = 0;	//used for sleep mode (turn off light)
unsigned int heartbeat_timer = 0;	// used for heartbeat led

void setup()
{
	/*initialize ios*/
}
void loop()
{
	timers();
	heartbeat_control();
	light_control();
}

void light_control()
{
	static int light_state = 0;

	switch(light_state)
	{
		case 0:				//OFF 
			turn_light_off();
			light_timeout_timer = 0; // timer used in time out for the ON light_state
			if(button_pressed() == 1)
				light_state = 1;
			break;
		case 1:				//ON
			turn_light_on();
			if((button_pressed() == 1)     ||
			   (light_timeout_timer >= 200)   ) // 20 seconds
				light_state = 0;
			break;
		default:
			light_state = 0;
			turn_light_off();
			break;
	}
}

int button_pressed(void)
{
	static bool allow_button_to_be_read;
	
	if(digitalRead(button_pin) == 0)
		 allow_button_to_be_read = 1;

	if((digitalRead(button_pin) == 1) && (allow_button_to_be_read == 1 ))
	{ 
		if(timer1 >= 5) // debounce for half
		{
			allow_button_to_be_read = 0;
			return 1;
		}
	}
	else
	{
		timer1 = 0;
	}
	return 0;
}
void heartbeat_control(void)
{// same as any blinking LED function seeing in previous lectures
	if(heartbeat_timer < 10)
	{
		digitalWrite(heart_beat_pin,HIGH);
	}
	else if(heartbeat_timer < 20)
	{
		digitalWrite(heart_beat_pin,LOW);
	}
	else
	{
		heartbeat_timer = 0;
	}
}

void turn_light_on(void)
{
	digitalWrite(light_pin,HIGH);
}

void turn_light_off(void)
{
	digitalWrite(light_pin,LOW);
}


void timers(void)
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 100s
		millis_old = millis_old + interval;
		timer1++;
		light_timeout_timer++;
		heartbeat_timer++;
	}
	if(millis_old > millis())
	{ //if you run for a very long time, correct overflow
		millis_old = millis();	
	}		
}
