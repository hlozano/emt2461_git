/*very basic program to simulate a basic elevator that is manually controlled to run or stop
the controlling here is done by a serial port*/

/*		INTRO TO FINITE STATE MACHINES		*/
int state = 0;
bool demand_1 = 0;
bool demand_2 = 0;
bool demand_3 = 0;

int destination = 0;
int position = 1;


void timers(void);

void elevator_control(void);


void motor_stop(void);
void motor_run_up(void);
void motor_run_dn(void);




void setup()
{               
	Serial.begin(9600); 
	pinMode(up_led_pin, OUTPUT);
	pinMode(dn_led_pin, OUTPUT);
}
void loop()
{
  timers();
  read_demand_buttons();
  read_position();
	elevator_control();
	receive_serial();
	transmit_serial();
}


void elevator_control(void)
{
	switch(state)
	{
	case 1:
		motor_stop()
		if(demand_2 == 1)
		{
			state = 4;
			destination = 2;
		}
		if(demand_3 == 1)
		{
			state = 4;
			destination = 3;
		}
		break;
	case 2:
		motor_stop()
		if(demand_1 == 1)
		{
			state = 5;
			destination = 1;
		}
		if(demand_3 == 1)
		{
			state = 4;
			destination = 3;
		}
		break;	
	case 3:	
		motor_stop()
		if(demand_1 == 1)
		{
			state = 5;
			destination = 1;
		}
		if(demand_2 == 1)
		{
			state = 5;
			destination = 2;
		}
		break;
	case 4:
		motor_run_up();
		if(position == destination)
		{
			if (destination == 2)
				state = 2;
			if (destination == 3)
				state = 3;
		}
	case 5:
		motor_run_dn();
		if(position == destination)
		{
			if (destination == 1)
				state = 1;
			if (destination == 2)
				state = 2;
		}		
	}
}







void motor_stop()
{

}
void motor_run_up()
{

}
void motor_run_dn()
{

}

void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
		millis_old = millis_old + interval;
  }
  if(millis_old > millis())
  { //if you run for a very long time, correct overflow
    millis_old = millis();  
  }   
}





