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
unsigned int timer3 = 0;	// used for heartbeat led

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
	static int light_state;

	//STATE MACHINE USING IF AND ELSE IF STATEMENTS
	// if(light_state == 0)
	// {
	// 	turn_light_off();
	// 	if(button_pressed() == 1)
	// 	{
	// 		light_timeout_timer = 0;
	// 		light_state = 1;
	// 	}
	// }
	// else if (light_state == 1)
	// {
	// 	turn_light_on();
	// 	if(light_timeout_timer>36000)
	// 	{
	// 		light_state = 0;
	// 	}
	// }




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
			if(light_timeout_timer >= 36000)
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
	if(digitalRead(button_pin) == 1) 
	{ 
		if(timer1 > 10) // debounce for one second
			return 1;
	}
	else
	{
		timer1 = 0;
	}
	return 0;
}
void timers(void)
{
	static unsigned long ms_runtime;
	static int one_ms_timer;
	if(millis() > (ms_runtime + 1))
	{
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
	{ // ELSE PART IS NOT NEEDED unless you 
	  // are running your code for more than _40___ days
		ms_runtime = millis();
	}
	if(one_ms_timer > 99)
	{ // our choice for 99 gives us increments of 100 ms
		timer1++;
		light_timeout_timer++;
		timer3++;
		one_ms_timer = 0;
	}
}
void heartbeat_control(void)
{// same as any blinking LED function seeing in previous lectures
	if(timer3 < 10)
	{
		digitalWrite(heart_beat_pin,HIGH);
	}
	else
	{
		digitalWrite(heart_beat_pin,LOW);
		if(timer3>=20)
			timer3 = 0;
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

