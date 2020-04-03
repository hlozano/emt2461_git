/*		DC motor control program. One direction only.		*/

unsigned long ms_runtime;
int one_ms_timer;

unsigned long motor_tmr;
unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3; // timer3 is incremented every 100ms = 0.1s
const int motorspeed_pin = 10;


void setup()
{
    Serial.begin(9600); 
}
void loop()
{
    timers();
    drive_motor();
}
void drive_motor()
{
  static int motor_speed_value = 0;
  if(motor_tmr>50)
  { // comes in every 5 seconds = 50 x 0.1 sec
    if(motor_speed_value < 250)
		motor_speed_value = motor_speed_value + 25;
	else
	{
		motor_speed_value = 255;
		Serial.println("Running full speed");
	}
	motor_tmr = 0;
    Serial.println(motor_speed_value);
  }
  analogWrite(motorspeed_pin,motor_speed_value);
}

void timers(void)
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
		timer1++;
		timer2++;
		timer3++;
		motor_tmr++;
        one_ms_timer = 0;
	}

}

