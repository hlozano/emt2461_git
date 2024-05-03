void train_stop(void);				// stop train
void train_forward(void);			// move train forward
void train_reverse(void);			// move train reverse
void train_reverse_low_speed(void);	// move train reverse @ low speed
int car_at_station_A(void);			// read sensor @ station A
int car_at_station_B(void);			// read sensor @ station B
int e_brake_engaged(void);			// tells me ebrake is engaged

void FSM4_control(void)
{
	static state = 0;
	switch(state)
	{
		case 0:
			train_stop();
			if(e_brake_engaged() == 0)
			{
				state = 4;
			}
			break;
		case 1:
			train_forward();
			
			if(e_brake_engaged() == 1)
			{
				state = 0;
			}
			else if(car_at_station_B() == 1)
			{
				state = 3;
				time_in_station_tmr = 0;
			}
			break;
		case 2:
			train_reverse();
			if(e_brake_engaged() == 1)
			{
				state = 0;
			}
			else if(car_at_station_A() == 1)
			{
				state = 3;
				time_in_station_tmr = 0;
			}
			break;
		case 3:
			train_stop();
			if((time_in_station_tmr > 60) && 
					(car_at_station_B() == 1))
			{
				state = 2;
			}
			if((time_in_station_tmr > 60) && 
					(car_at_station_A() == 1))
			{
				state = 1;
			}
			break;			
		case 4:
			train_reverse_low_speed();
			if(car_at_station_A() == 1)
			{
				state = 3;
				time_in_station_tmr = 0;
			}
			break;
	};
	
}






