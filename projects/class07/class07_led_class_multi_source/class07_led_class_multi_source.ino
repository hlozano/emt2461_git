#include "myled.h"

LED newLED1(13);
LED newLED2(14);

void setup() 
{                
	newLED1.turnon();
	newLED2.turnoff();
}

void loop() 
{
	newLED1.toggle();
	newLED2.toggle();
	delay(1000);              
}  
