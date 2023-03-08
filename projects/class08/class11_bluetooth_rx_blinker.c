/*		TIMERS MADE EASY BY HERNAN LOZANO		*/

unsigned long ms_runtime;
int one_ms_timer;

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3; // timer3 is incremented every 100ms = 0.1s
unsigned long timer4; // timer4 is incremented every 100ms = 0.1s
unsigned long timer5; // timer5 is incremented every 100ms = 0.1s

const int LED1 = 13;
int rx_command = 0;
char mystring[] = " ";

void light_control(void);

void setup()
{               
   Serial.begin(9600); 
    pinMode(LED1, OUTPUT);      
}
void loop()
{
    timers();
    bluetooth_receive_data();
    light_control();
}
void light_control(void)
{
		switch (rx_command)
	{
        case '0': 
			flash_led_0_2();
			break;
		case '1': 
			flash_led1();
			break;
		case '2': 
			flash_led2();
			break;
		case '3': 
			flash_led3();
			break;
		case '4': 
			flash_led4();
			break;
		case '5': 
			flash_led5();
			break;
		default:
			turn_off();
	}
}
void bluetooth_receive_data(void)
{
  static int rx_seq;
  static int temp_command;
 
  if (Serial.available() > 0) 
  {
      inByte = Serial.read();
      Serial.print(" echo:");
      Serial.println(inByte);
  

      switch(rx_seq)
      {
        case 0:
          if(inByte == '*')
              rx_seq++;
          break;
        case 1:
          //unpack next byte
          rx_seq++;
          break;
         case 2:
          //unpack next byte
          rx_seq++;
          break;
        case 3:
          //unpack next byte
          rx_seq++;
          break;
        case 4:
          //unpack next byte
          rx_seq++;
          break;
        case 5:
          //unpack next byte
          rx_seq++;
          break;
        case 6:
          //unpack next byte
          rx_seq++;
          break;
        case 7:
          //unpack next byte
          rx_seq++;
          break;
        case 8:
          //unpack next byte
          rx_seq++;
          break;
        case 9:
          //unpack next byte
          rx_seq++;
          break;
        case 10:
          //unpack next byte
          temp_command = inByte;
          rx_seq++;
          break;
         case 11:
           if(inByte == '#') // test that it was a good packet
             rx_command = temp_command;
           rx_seq =0; // good or not start all over
          break;
           

            
      }
  }
  
}
void turn_off(void)
{
	digitalWrite(LED1,LOW);
}
void flash_led_0_2(void)
{
	if(timer1<1)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=2) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer get cleared?
	}  
}
void flash_led1() 
{
	if(timer1<5)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer1>=10) //(between 10 and 20 - another 1 s)
			timer1 = 0;	//When does the timer get cleared?
	}
}
void flash_led2()
{
	if(timer2<10)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer2>=20)
			timer2 = 0;	//When does the timer get cleared?
	}
}
void flash_led3()
{
	if(timer3<15)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer3>=30)
			timer3 = 0;	//When does the timer get cleared?
	}
}
void flash_led4()
{
	if(timer4<20)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer4>=40)
			timer4 = 0;	//When does the timer get cleared?
	}
}
void flash_led5()
{
	if(timer5<25)			//Check timer and execute action 
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(timer5>=50)
			timer5 = 0;	//When does the timer get cleared?
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
		timer2++;
		timer3++;
		timer4++;
		timer5++;
	}	
  if(millis_old > millis())
  { //if you run for a very long time, correct overflow
    millis_old = millis();  
  }   
}
