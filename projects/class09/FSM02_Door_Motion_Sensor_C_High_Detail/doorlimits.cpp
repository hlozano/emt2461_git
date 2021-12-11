#import <Arduino.h>
#include "main.h"
#include "timers.h"

#define SIMULATE_DOORS 1

int is_sensor_active(void);
int is_door_closed(void);
int is_door_open(void);


#define DOOR_CLOSE_LIMIT_PIN 9
#define DOOR_OPEN_LIMIT_PIN 8
#define MOTION_SENSOR_PIN 7

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
	  if (sim_door_position > 95)
		return 1;
	  else 
		return 0;
	}


	int is_door_open()
	{
	  if(sim_door_position < 5)
		return 1;
	  else
		return 0;
	}

#endif
