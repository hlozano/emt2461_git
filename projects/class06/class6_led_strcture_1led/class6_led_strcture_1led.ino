/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 struct LED 
 {
   int addr;
   int dir; // 0 for input 1 for output
 } ;
 
 struct LED newLED1;
 
 struct LED newLED2;

void setup() 
{                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  
  newLED1.addr = 13;
  pinMode(newLED1.addr, OUTPUT);   
  newLED1.dir = 1;  
}

void loop() 
{
  digitalWrite(newLED1.addr , HIGH);   // set the LED on
  delay(2000);              // wait for a second
  digitalWrite(newLED1.addr , LOW);    // set the LED off
  delay(2000);              // wait for a second
}