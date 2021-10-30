/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7

  http://www.arduino.cc/en/Tutorial/Ping

  This example code is in the public domain.
*/

const int nmb_samples = 5;

unsigned long ping_tmr = 0; // incremented every 100ms = 0.1s
unsigned long display_tmr = 0;


int inches = 0;
int cm = 0;
int analog_output_pin = 3;

int DistanceCm;
int D_cm_average = 0;
int old_D_cm_average = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
	
}

void loop()
{
  	analogWrite(analog_output_pin,D_cm_average);
    timers();
	if(display_tmr >=5)
	{
		display_tmr = 0;
		print_to_serial();
	}
	if(ping_tmr >= 1)
	{//every 100 ms
		ping_tmr = 0;
		DistanceCm = 0.01723 * readUltrasonicDistance(7, 7);;
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

	static unsigned long ms_runtime;
	static int one_ms_timer;
	if(millis() > ms_runtime)
	{
		ms_runtime++;
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