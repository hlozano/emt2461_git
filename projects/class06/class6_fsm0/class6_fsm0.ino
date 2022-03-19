//DEFINE ALL TIMERS AS UNSIGNED VARIABLES	
unsigned long timer1 = 0; // timer1 increments every 100ms = 0.1s
unsigned long go_input_dbnc_tmr = 0;
unsigned long stop_input_dbnc_tmr = 0;
unsigned long waiting_in_yellow_tmr = 0;

const int RED_LED_OUTPUT = 13;
const int YEL_LED_OUTPUT = 12;
const int GRN_LED_OUTPUT = 11;

const int GO_INPUT = 2;
const int STOP_INPUT = 3;

int traffic_light_state = 0; //0=red, 1=yellow, 2=green;
int traffic_light_state_prev = -1;

void setup()
{ // initialize the digital pin as an output.               
	pinMode(RED_LED_OUTPUT, OUTPUT);     
	pinMode(YEL_LED_OUTPUT, OUTPUT);     
	pinMode(GRN_LED_OUTPUT, OUTPUT);

	pinMode(GO_INPUT, INPUT);
	pinMode(STOP_INPUT, INPUT);
	Serial.begin(9600);
}
void loop()
{	//run loop forever
	int go_command = 0;
	int stop_command = 0;
	timers();
	//process inputs
	if((digitalRead(STOP_INPUT) == 1) && (stop_input_dbnc_tmr >= 5))
	{
		stop_command = 1;		
		go_command = 0;
	}
	else if((digitalRead(GO_INPUT) == 1) && (go_input_dbnc_tmr >= 5))
	{
		stop_command = 0;		
		go_command = 1;	
	}
	else
	{
		stop_command = 0;		
		go_command = 0;			
	}

	if(digitalRead(STOP_INPUT) == 0)
		stop_input_dbnc_tmr = 0;
	if(digitalRead(GO_INPUT) == 0)
		go_input_dbnc_tmr = 0;


	//system logic
	if(traffic_light_state == 0) // red	
	{	
		if(go_command == 1)
			traffic_light_state = 2;
	}
	else if(traffic_light_state == 1) //yellow
	{	
		if(waiting_in_yellow_tmr >= 50)
			traffic_light_state = 0;	
	}
	else if(traffic_light_state == 2)//green 
	{
		waiting_in_yellow_tmr = 0;
		if(stop_command == 1)
			traffic_light_state = 1;
	}

	//set outputs
	if(traffic_light_state == 0)
	{
		digitalWrite(RED_LED_OUTPUT,1);
		digitalWrite(YEL_LED_OUTPUT,0);
		digitalWrite(GRN_LED_OUTPUT,0);
	}
	if(traffic_light_state == 1)
	{
		digitalWrite(RED_LED_OUTPUT,0);
		digitalWrite(YEL_LED_OUTPUT,1);
		digitalWrite(GRN_LED_OUTPUT,0);
	}
	if(traffic_light_state == 2)
	{
		digitalWrite(RED_LED_OUTPUT,0);
		digitalWrite(YEL_LED_OUTPUT,0);
		digitalWrite(GRN_LED_OUTPUT,1);
	}

	if(traffic_light_state_prev != traffic_light_state)
	{
		Serial.print("traffic_light_state = ");
		Serial.println(traffic_light_state);
	}
	traffic_light_state_prev = traffic_light_state; 
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
	{	
		one_ms_timer = 0;
		timer1++;
		go_input_dbnc_tmr++;
		stop_input_dbnc_tmr++;
		waiting_in_yellow_tmr++;
	}
}



