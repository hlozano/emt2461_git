/*		MCU # 1 		MASTER			*/
//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
unsigned long timer1; // timer1 is incremented every 100ms = 0.1s

int blink_rate = 0;
char tx_data = '0';

int send_first_packet = 1;

void setup()
{              
	Serial.begin(9600);  
}
void loop()
{
    timers();
	if((timer1>100) || (send_first_packet == 1)) // every 10 seconds.... 0 ,1,2,3,4,5,0,1,2,3,4,5
	{
		send_first_packet = 0;
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
	static unsigned long ms_runtime;
	static int one_ms_timer;

	if(millis() > ms_runtime)
	{
		ms_runtime++;
		one_ms_timer++;  
	}
	else if(ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99)
	{
		timer1++;
		one_ms_timer = 0;
	}

}

