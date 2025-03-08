/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
struct LED_t //name of the template used for this structure
{
 int addr;
 int status; 
};

struct LED_t mycool_LED; //LED1 is an instance of the LED data type (a.k.a structure template)
 
void setup() 
{                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards: 
  mycool_LED.addr = 13;
  pinMode(mycool_LED.addr, OUTPUT);  
  digitalWrite(mycool_LED.addr, LOW);    // set the LED off 
  mycool_LED.status = 0;  
}

void loop() 
{
  digitalWrite(mycool_LED.addr, HIGH);   // set the LED on
  mycool_LED.status = 1;  
  delay(2000);              // wait for a second

  digitalWrite(mycool_LED.addr, LOW);    // set the LED off
  mycool_LED.status = 0;  
  delay(2000);              // wait for a second
}