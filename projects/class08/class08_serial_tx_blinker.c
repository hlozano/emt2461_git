 /*		MCU # 1 		MASTER			*/
//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
unsigned long timer1; // timer1 is incremented every 100ms = 0.1s

int blink_rate = 0;
char tx_data = '0';

int send_first_packet = 1;

void heartbeat_led(void);

void setup()
{              
	Serial.begin(9600);  
}
void loop()
{
    timers();
	if((timer1>100) || (send_first_packet == 1)) // every 10 seconds.... '0' ,1,2,3,4,5,0,1,2,3,4,5
	{		
		timer1 = 0;		
		send_first_packet = 0;
		tx_data = '0'+ blink_rate;
		Serial.print(tx_data);
		blink_rate++;
		if(blink_rate>5)
			blink_rate = 0;
	}
}

void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
    millis_old = millis_old + interval;
	 timer1++;
  }
  if(millis_old > millis())
  { //if you run for a very long time, correct overflow
    millis_old = millis();  
  }   
}

