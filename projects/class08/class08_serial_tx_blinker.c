/*		TIMERS MADE EASY BY HERNAN LOZANO		*/

/*		MCU # 1 		MASTER			*/

unsigned long ms_runtime;
int one_ms_timer;

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
unsigned long timer1; // timer1 is incremented every 100ms = 0.1s

int blink_rate = 0;
char tx_data = '0';

void setup()
{              
	Serial.begin(9600);  
}
void loop()
{
    timers();
	if(timer1>100) // every 10 seconds.... 0 ,1,2,3,4,5,0,1,2,3,4,5
	{
		timer1 = 0;
		tx_data = '0'+ blink_rate;
		Serial.print(tx_data);
		blink_rate++;
		if(blink_rate>5)
			blink_rate = 0;
	}
	

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
		one_ms_timer = 0;
	}

}

