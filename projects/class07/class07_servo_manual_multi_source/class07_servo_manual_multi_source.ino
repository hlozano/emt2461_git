#include <Servo.h> 
#include "timers.h" 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
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
