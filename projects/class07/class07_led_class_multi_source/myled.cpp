#include "myled.h"
#import <Arduino.h>

LED::LED(int pin)
{
	addr = pin;
	ledstate = 0;
	pinMode(addr, OUTPUT); 	
	turnoff();
}
void LED::turnon()
{
	ledstate = 1;
	digitalWrite(addr,ledstate);
}
void LED::turnoff()
{
	ledstate = 0;
	digitalWrite(addr,ledstate);
}
void LED::toggle()
{
	ledstate= !ledstate;
	digitalWrite(addr,ledstate);
}
 
