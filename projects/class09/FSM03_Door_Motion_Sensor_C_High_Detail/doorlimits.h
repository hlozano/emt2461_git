#ifndef DoorLimitsDef
	#define DoorLimitsDef

	#define DOOR_CLOSE_LIMIT_PIN 9
	#define DOOR_OPEN_LIMIT_PIN 8
	#define MOTION_SENSOR_PIN 7
	
	extern int is_sensor_active(void);
	extern int is_door_closed(void);
	extern int is_door_open(void);
	
#endif
