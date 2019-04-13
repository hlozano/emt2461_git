
unsigned long ms_runtime;
int one_ms_timer;

unsigned long ping_tmr = 0; // incremented every 100ms = 0.1s
unsigned long display_tmr = 0;

#include<NewPing.h>

#define  TRIGGER_PIN  8
#define  ECHO_PIN     7
#define MAX_DISTANCE 500

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int DistanceIn;
int D_in_average = 0;
const int nmb_samples = 50;

void setup()
{
    Serial.begin(9600);  
}
void loop()
{ 
    inctimers();
	if(display_tmr >=5)
	{
		display_tmr = 0;
		print_to_serial();
	}
	if(ping_tmr >= 1)
	{//every 100 ms
		ping_tmr = 0;
		DistanceIn = sonar.ping_in();
//		D_in_average = (        OLD TOTAL          -  OLD average + New Reading)/nmb_samples;
		D_in_average = (nmb_samples * D_in_average - D_in_average + DistanceIn)/nmb_samples;
		//D_in_average = (int)((float)(nmb_samples * D_in_average - D_in_average + DistanceIn)/(float)nmb_samples);
		// This type casting allows me to keep some more accurate values
	}


}
void print_to_serial()
{
		Serial.print("Ping: ");
		Serial.print(D_in_average); // Convert ping time to distance and print result 					  // (0 = outside set distance range, no ping echo)
		Serial.println(" in     ");
}


void inctimers(void)
{
	int i;
	if(millis() > (ms_runtime + 1))
	{
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}
	else if( ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99)
	{
		ping_tmr++;
		display_tmr++;
		one_ms_timer = 0;
	}

}

