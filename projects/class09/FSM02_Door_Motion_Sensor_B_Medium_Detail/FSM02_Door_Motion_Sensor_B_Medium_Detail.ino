unsigned long ms_runtime;
unsigned int one_ms_timer;
unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer1; // timer1 is incremented every 100ms = 0.1s

// #define CLOSED_STATE 0
// #define OPENING_STATE 1
// #define OPEN_STATE 2
// #define CLOSING_STATE 3

const int CLOSED_STATE = 0;
const int OPENING_STATE = 1;
const int OPEN_STATE = 2;
const int CLOSING_STATE = 3;

const int LED1 = 13;

int door_state = 0;

 
 void door_control(void);
 int is_door_closed(void);
 int is_door_open(void);
 int is_sensor_active(void);

 void motor_close(void); // CW OR CCW
 void motor_open(void);
 void motor_stop(void);



void setup()
{
	//initilize inputs, memory, etc
}

void loop()
{
	timers();
	flash_led1();
	door_control();
}

/*
 ROUTINE USED TO MONITOR AND 
 CONTROL THE STATE OF THE DOORS
*/
void door_control(void)
{
	switch(door_state)
	{
		case CLOSED_STATE:
			motor_stop();
			if(is_sensor_active()==1)
				door_state = OPENING_STATE;
			break;
		case OPENING_STATE:
			motor_open(); 
			if(is_door_open() == 1)
			{
				door_state = OPEN_STATE;
			}
			break;
		case OPEN_STATE:
			motor_stop();
			if(is_sensor_active() == 1)
				timer1 = 0;
			if(timer1>= 50)
				door_state = CLOSING_STATE;
			break;
		case CLOSING_STATE:
			motor_close(); // keep closing
			if(is_door_closed() == 1)
				door_state = CLOSED_STATE;
			else if(is_sensor_active() == 1)
				door_state = OPENING_STATE;
			break;
		default:
			door_state = CLOSED_STATE;
			break;
	}
}
void timers(void)
{
	int i;
	if(millis() > (ms_runtime + 1))
	{
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99) // every 100 ms
	{
		if(timer1 <4000000000)
			timer1++;
		one_ms_timer = 0;
	}
}

void flash_led1() 
{
	if(timer1<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=20) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer get cleared?
	}
}

 int is_door_closed(void)
 {
 	//monitor an input that will tell me door is closed 

 }
 int is_door_open(void)
 {
 	//monitor an input that will tell me door is open 


 }
 int is_sensor_active(void)
 {
 	// read motion sensor

 }

 void motor_close(void)
 {


 }// CW OR CCW
 void motor_open(void)
 {


 }
 void motor_stop(void)
 {


 }