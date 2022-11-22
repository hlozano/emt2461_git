int run_state = 0;	//run_state = 0 stop
					//run_state = 1 move_forward
					//run_state = 2 rotate_right
					//run_state = 3 rotate_left

int failed_attempts = 0;
int distance = 0; // 

//system timers
long unsigned heartbeat_timer = 0;					
long unsigned timer1 = 0;					
long unsigned timer2 = 0;					
		
void distance_sensor_control(void);
void robot_control(void);

void stop(void);             //motor functions
void forward(void);          //motor functions
void rotate_right(void);     //motor functions
void rotate_left(void);      //motor functions

void reverse(void);        //motor functions

void timers(void);        // timers routine for system 
void heartbeat_led(void);	//blink led

void heartbeat_led(void)
{
	if(heartbeat_timer<1)			//heartbeat_timer is a one second timer
		digitalWrite(LED1,HIGH); 
	else if(heartbeat_timer<2)
	{
		digitalWrite(LED1,LOW);
	}
	
	if(heartbeat_timer >=2)
	{
		heartbeat_timer = 0; //When does the timer get cleared?
	}
}					
void setup()
{
	
}
void loop()
{
	timers();
	heartbeat_led(); // diagnostics (flash every second)
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
	
/*
	if(distance_reading_timer >= 2) // reading every 200ms
	{
		distance_reading_timer = 0;	
		d = reading from Ultrasonic;

	}
*/
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
//advance version of timers
//it allows timers of 1 ms, 10ms 100 ms and up to 1s increments
void timers(void)
{
	static unsigned long ms_runtime;
	static int one_ms_timer;
	static int ten_ms_timer;
	static int hun_ms_timer;

	if(millis() > ms_runtime)
	{//program falls here every 1 ms	
		ms_runtime++;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
	{
		ms_runtime = millis();
	}
	if(one_ms_timer > 9)
	{//program falls here every 10 ms
		one_ms_timer = 0;
		ten_ms_timer++;
	}
	if(ten_ms_timer > 9)
	{//program falls here every 100 ms
		ten_ms_timer = 0;
		hun_ms_timer++;
		//user timers
		timer1++;
		timer2++;
	}
	if(hun_ms_timer > 9)
	{//program falls here every 1000ms = 1s
		hun_ms_timer = 0;
		//user timers
		heartbeat_timer++;
	}
}
