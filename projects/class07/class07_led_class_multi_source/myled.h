/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
#ifndef myled_H     // Prevent duplicate definition
    #define myled_H
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
#endif
