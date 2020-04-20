
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created  
				
int door_state;
	//door_state = 0 -> door is closed
	//door_state = 1 -> door is opening 
	//door_state = 2 -> door is open
	//door_state = 3 -> door is closing

#define CLOSED_STATE 0
#define OPENING_STATE 1
#define OPEN_STATE 2
#define CLOSING_STATE 3


const int LED_pin = 13;

int sim_door_position = 0;
/*
sim_door_position ~ 000 door fully open
sim_door_position ~ 100 door fully closed
*/
void led_control(void);
void door_control(void);
void motor_control(void);
void serial_debugger(void);
void door_simulator(void);

//DOOR LIMITS
#define SIMULATE_DOORS 1

#define DOOR_CLOSE_LIMIT_PIN 9
#define DOOR_OPEN_LIMIT_PIN 8
#define MOTION_SENSOR_PIN 7

int is_sensor_active(void);
int is_door_closed(void);
int is_door_open(void);


//TIMERS


unsigned long timer1 = 0; // timer1 is incremented every 100ms = 0.1s
unsigned long led_tmr = 0;
unsigned long sensor_tmr = 0;
unsigned long time_to_block = 0;
unsigned long debug_print_tmr = 0;
unsigned long sim_door_position_tmr = 0;

void timers(void);


#if (SIMULATE_DOORS == 0)			// COMPILER FLAGS
	int is_door_closed(void)
	{
		if(digitalRead(DOOR_CLOSE_LIMIT_PIN) == 1)
			return 1;
		else
			return 0;
	}
	int is_door_open(void)
	{
		if(digitalRead(DOOR_OPEN_LIMIT_PIN) == 1)
			return 1;
		else
			return 0;
	}
	int is_sensor_active(void)
	{
		if(digitalRead(MOTION_SENSOR_PIN) == 1)
			return 1;
		else
			return 0;
	}
	
#else							//ELSE TO COMPILER FLAG

	int is_sensor_active(void)
	{
		if(time_to_block > 0)
			return 1;
		else
			return 0;	
	}


	int is_door_closed()
	{
	  if(sim_door_position < 5)
		return 1;
	  else 
		return 0;
	}


	int is_door_open()
	{
	  if (sim_door_position > 95)
		return 1;
	  else
		return 0;
	}

#endif



void setup(void)
{
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object 
}
void loop()
{
	timers();
	led_control();
	door_control();
	motor_control();
	door_simulator(); //What if I want to simulate my doors. 
	serial_debugger();
	
}

void door_control(void)
{
	
	switch(door_state)
	{
		case CLOSED_STATE:
			//door_state = 0 -> door is closed
			if(is_sensor_active() == 1)
			{
				door_state = OPENING_STATE;
			}
			break;
		case OPENING_STATE:
			//door_state = 1 -> door is opening 
			if(is_door_open() == 1)
			{
				door_state = OPEN_STATE;
				timer1 = 0;
			}
			break;
		case OPEN_STATE:
			//door_state = 2 -> door is open
			if(is_sensor_active() == 1)
			{
				timer1 = 0;
			}
			else if(timer1 >= 50)// our timers are 100th ms.. so 50 = 5 secs 
			{
				door_state = CLOSING_STATE;
			}
			break;
		case CLOSING_STATE:
			//door_state = 3 -> door is closing
			if(is_sensor_active() == 1)
			{
				door_state = OPENING_STATE;
			}
			if(is_door_closed() == 1)
			{
				door_state = CLOSED_STATE;
			}
			break;
	}
}


void led_control(void)
{
	if(led_tmr <10)
		digitalWrite(LED_pin,LOW);
	else if(led_tmr< 20)
		digitalWrite(LED_pin,HIGH);
	else
    {
		led_tmr = 0;
     }
}

void motor_control(void)
{	
	
	switch(door_state)
	{
		case CLOSED_STATE://door_state = 0 -> door is closed
			 myservo.write(89); 
			break;
		case OPENING_STATE://door_state = 1 -> door is opening 
			 myservo.write(180); 
			break;
		case OPEN_STATE://door_state = 2 -> door is open
			 myservo.write(89); 
			break;
		case CLOSING_STATE://door_state = 3 -> door is closing
			 myservo.write(0); 
			break;
	}
}

void serial_debugger(void)
{
	static int prev_door_state = 0;
	static int prev_sim_door_position = 0;
	static int prev_sim_door_position_tmr = 0;
	static int prev_time_to_block = 0;	


	if((debug_print_tmr >= 20) 
		// || (prev_door_state != door_state)
		// || (prev_sim_door_position != sim_door_position)
		// || (prev_sim_door_position_tmr != sim_door_position_tmr)
		// || (prev_time_to_block != time_to_block)
		)
	{
		debug_print_tmr = 0;
		switch(door_state)
		{

			case CLOSED_STATE:
				Serial.print("Doors are closed\n");
				break;
			case OPENING_STATE:
				Serial.print("Doors are opening\n");
				break;
			case OPEN_STATE:
				Serial.print("Doors are open\n");
				break;
			case CLOSING_STATE:
				Serial.print("Doors are closing\n");
				break;
			default:
				Serial.print("Doors are at unknown state\n ");
                Serial.print(door_state);
				break;
		}
		Serial.print("Door state =  ");
		Serial.print(door_state); 
		Serial.print("  Sim DoorPos =  ");       
		Serial.print(sim_door_position); 
		Serial.print("  Time to Block =  ");
		Serial.println(time_to_block);
	}
	prev_door_state = door_state;
	prev_sim_door_position = sim_door_position;
	prev_sim_door_position_tmr = sim_door_position_tmr;
	prev_time_to_block = time_to_block;	
}

void door_simulator(void)
{

	char ch;
  
	if (Serial.available())
	{

		ch = Serial.read();// char = '3'
		if(ch >= '0' && ch <= '9')
		{
		   time_to_block = ch - '0'; // at this point time to block is a number in [0,9]
		}
		time_to_block = time_to_block * 10; //number 3... becomes 30  - > for three seconds
        Serial.print(" char and time to block ");
        Serial.print(ch);
        Serial.print(" ");
        Serial.println(time_to_block);
	}
    if(sim_door_position_tmr >= 1) // how often the sim_door_position changes
    {
      if(door_state == 3)
      {//opening
        if(sim_door_position>0)
          sim_door_position--;
      }
      else if(door_state == 1)
      {//closing
        if(sim_door_position<100)
          sim_door_position++;
      }
      else if(door_state == 0)
      {
        sim_door_position = 0;
      }
      else if(door_state == 2)
      {
        sim_door_position = 100;
      }

      sim_door_position_tmr = 0;
    } 	   
}


void timers(void)
{
	static unsigned long ms_runtime = 0;
	static unsigned int one_ms_timer = 0;

	if(millis() > ms_runtime)
	{
		ms_runtime++;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99) // every 100 ms
	{
		one_ms_timer = 0;
		if(led_tmr <4000000000)
			led_tmr++;
		if(timer1 <4000000000)
			timer1++;
		if(sensor_tmr <4000000000)
			sensor_tmr++;
		if(debug_print_tmr <4000000000)
			debug_print_tmr++;
		if(sim_door_position_tmr <4000000000)
		   sim_door_position_tmr++;
	   	if(time_to_block > 0)
			time_to_block--;
                
	}
}

