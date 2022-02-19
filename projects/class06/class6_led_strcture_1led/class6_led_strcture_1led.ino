/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 struct LED_t //name of the template used for this structure
 {
   int addr;
   int state; 
 } ;


 struct LED_t newLED1; //LED1 is an instance of the LED data type (a.k.a structure template)
 

void setup() 
{                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  
  newLED1.addr = 13;
  pinMode(newLED1.addr, OUTPUT);  
  digitalWrite(newLED1.addr, LOW);    // set the LED off 
  newLED1.state = 0;  
}

void loop() 
{
  digitalWrite(newLED1.addr, HIGH);   // set the LED on
  newLED1.state = 1;  
  delay(2000);              // wait for a second

  digitalWrite(newLED1.addr, LOW);    // set the LED off
  newLED1.state = 0;  
  delay(2000);              // wait for a second
}