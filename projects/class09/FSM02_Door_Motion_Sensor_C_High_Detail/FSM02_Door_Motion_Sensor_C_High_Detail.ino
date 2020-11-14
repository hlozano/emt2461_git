
#include <Servo.h> 
#include "doorlimits.h"
#include "timers.h"
#include "main.h" 
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
			if(read_sensor() == 1)
			{
				door_state = OPENING_STATE;
			}
			break;
		case OPENING_STATE:
			//door_state = 1 -> door is opening 
			if(read_dooropenlimit() == 1)
			{
				door_state = OPEN_STATE;
				timer1 = 0;
			}
			break;
		case OPEN_STATE:
			//door_state = 2 -> door is open
			if(read_sensor() == 1)
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
			if(read_sensor() == 1)
			{
				door_state = OPENING_STATE;
			}
			if(read_doorcloselimit() == 1)
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
	if(debug_print_tmr >= 10)
	{
		debug_print_tmr = 0;
		switch(door_state)
		{

			case CLOSED_STATE:
				Serial.println("Doors are closed\n");
				break;
			case OPENING_STATE:
				Serial.println("Doors are opening\n");
				break;
			case OPEN_STATE:
				Serial.println("Doors are open\n");
				break;
			case CLOSING_STATE:
				Serial.println("Doors are closing\n");
				break;
			default:
				Serial.print("Doors are at unknown state ");
                Serial.println(door_state);
				break;
		}
		Serial.print("Door state =  ");
		Serial.print(door_state); 
		Serial.print("  Sim DoorPos =  ");       
		Serial.print(sim_door_position); 
		Serial.print("  Time to Block =  ");
		Serial.println(time_to_block);
	}
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
