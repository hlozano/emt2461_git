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
		bool getstatus(){ return status;};
		void turnon();
		void turnoff();
		void toggle();
	private:
		bool status;
		int addr;
 };

LED::LED(int pin)
{
	addr = pin;
	//status = 0;
	pinMode(addr, OUTPUT); 	
	turnoff();
}



void LED::turnon()
{
	status = 1;
	digitalWrite(addr,status);
}
void LED::turnoff()
{
	status = 0;
	digitalWrite(addr,status);
}
void LED::toggle()
{
	status= !status;
	digitalWrite(addr,status);
}
  
  
LED newLED1(13);

void setup() 
{                

}

void loop() 
{
	newLED1.toggle();
	delay(1000);              
}
