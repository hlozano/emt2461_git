#include <Servo.h> 
#include "timers.h" 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
#define USE_BUILT_IN_LED 1
#if USE_BUILT_IN_LED == 1
const int LED1 = 13;
#else
const int LED1 CLOWN VALUE 12;
#endif

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{ 
	motor_manual_control();
	heart_beat();            
} 
void motor_manual_control(void)
{
	char ch;
	if (Serial.available())
	{
        ch = Serial.read();
		if(ch == '+')
		{
		   pos++;
		}
		if(ch == '-')
		{
		  pos--;
		}
		Serial.println(pos);
    }
    myservo.write(pos);              // tell servo to go to position in variable 'pos'  
}
void heart_beat(void)
{
	if(timer1<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else if(timer1<20)	
		digitalWrite(LED1,LOW); 
	else
		timer1 = 0;
}
