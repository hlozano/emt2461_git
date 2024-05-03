

#include<NewPing.h>

#define  TRIGGER_PIN  8
#define  ECHO_PIN     7
#define MAX_DISTANCE 500

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int DistanceCm;
int D_cm_average = 0;
int old_D_cm_average = 0;
const int nmb_samples = 5;

void setup()
{
    Serial.begin(9600);  
}
void loop()
{ 
    timers();
	if(display_tmr >=5)
	{
		display_tmr = 0;
		print_to_serial();
	}
	if(ping_tmr >= 1)
	{//every 100 ms
		ping_tmr = 0;
		DistanceCm = sonar.ping_cm();
		old_D_cm_average = D_cm_average;
//		D_cm_average = (        OLD TOTAL          -  OLD average + New Reading)/nmb_samples;
		//           = (     N      * OLD_AVERAGE ) -  OLD average + New Reading)/nmb_samples;
		D_cm_average = (nmb_samples * old_D_cm_average - old_D_cm_average + DistanceCm)/nmb_samples;
		//D_cm_average = (int)((float)(nmb_samples * old_D_cm_average - old_D_cm_average + DistanceIn)/(float)nmb_samples);
		// This type casting allows me to keep some more accurate values
	}


}
void print_to_serial()
{
		Serial.print("Ping: ");
		Serial.print(D_cm_average); // Convert ping time to distance and print result 					  // (0 = outside set distance range, no ping echo)
		Serial.println(" cm     ");
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
