
#include<NewPing.h>

unsigned long ping_tmr = 0; // incremented every 100ms = 0.1s
unsigned long display_tmr = 0;


#define  TRIGGER_PIN  8
#define  ECHO_PIN     7
#define  MAX_DISTANCE 500

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int DistanceIn;
int DistanceCm;

void setup()
{
    Serial.begin(9600);  
}
void loop()
{ 
    timers();
	if(display_tmr >=5)
	{// every 0.5 secs
		display_tmr = 0;
		print_to_serial();
	}
	if(ping_tmr >= 1)
	{//every 100 ms : This is if you want to get 10 reading in one second
		ping_tmr = 0;
		DistanceIn = sonar.ping_in();
	}


}
void print_to_serial()
{
		Serial.print("Ping: ");
		Serial.print(DistanceIn); // Convert ping time to distance and print result 					  // (0 = outside set distance range, no ping echo)
		Serial.println(" in     ");
}

void timers(void)
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	unsigned interval = 100; 	// meaning every 100ms

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 100s
		millis_old = millis_old + interval;
		ping_tmr++;
		display_tmr++;
	}
	if(millis_old > millis())
	{ //if you run for a very long time, correct overflow
		millis_old = millis();	
	}		
}
