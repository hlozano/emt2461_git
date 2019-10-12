/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 class LED 
 {
	public:
		LED(int pin);
		int getaddr(){return addr;};
		bool getstate(){ return ledstate;};
		void turnon();
		void turnoff();
		void toggle();
	private:
		bool ledstate;
		int addr;
 };

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
  




  
LED newLED1(13);


void setup() 
{                

}

void loop() 
{
	newLED1.toogle();
	delay(1000);              
}  