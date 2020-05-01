int run_state = 0;	//run_state = 0 stop
					//run_state = 1 move forward
					//run_state = 2 rotate_right
					//run_state = 3 rotate_left

int failed_attempts = 0;
int distance = 0; // 					
		
void distance_sensor_control(void);
void robot_control(void);

void stop(void);             //motor functions
void forward(void);          //motor functions
void rotate_right(void);     //motor functions
void rotate_left(void);      //motor functions
void reverse(void);      //motor functions
void timers(void);        //motor functions

					
void setup()
{
	
}
void loop()
{
	timers();
	flash_led1(); // diagnostics (flash every second)
	distance_sensor_control_1();
	robot_control();
}

void robot_control()
{
	//run_state = 0 stop
	//run_state = 1 move forward
	//run_state = 2 rotate_right
	//run_state = 3 rotate_left
	switch(run_state)
	{
		case 0:
			stop();	
			if(distance > 20)
			{
				run_state = 1;
			}
			else
			{//distance is less or equal to 20
				if(failed_attempts < 3)
				{
					failed_attempts++;
					run_state = 2;
					timer1 = 0;
				}
				else
				{
					timer2 = 0;
					run_state = 3;
					failed_attempts = 0;
				}
			}
			break;
		case 1:
			forward();
			if(distance < 20)
			{
				run_state = 0;				
			}
			break;	

		case 2:
			rotate_right();
			if(timer1 >= 20) // 2.0 seconds (based on 90 degrees rotation) - spinning one wheel only
			{				
				run_state = 0;
			}
			break;	
		case 3:
			rotate_left();
			if(timer2 >= 60)
			{
				run_state = 0;	
			}
			break;

    	default:
			break;		
	}

}

//function returns the distance in inches
void distance_sensor_control()
{

}
//move forward
void forward()
{

}
//move reverse
void reverse()
{

}
//rotate (right or left? : decide later)
void rotate_right()
{

}

void rotate_left()
{

}

void timers()
{

}


