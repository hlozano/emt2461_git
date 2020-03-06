/*		structures */
 struct LED 
 {
   int addr;
   int dir; // 0 for input 1 for output
  
 } ;
 
 struct LED newLED1;
 
 struct LED newLED2;

void setup() 
{                
  newLED1.addr = 13;
  pinMode(newLED1.addr, OUTPUT);   
  newLED1.dir = 1;  
  
  newLED2.addr = 14;
  pinMode(newLED2.addr, OUTPUT);   
  newLED2.dir = 1;  
}

void loop() 
{
  digitalWrite(newLED1.addr , HIGH);   // set the LED on
  digitalWrite(newLED2.addr , LOW);    // set the LED off
  delay(1000);              // wait for a second
  digitalWrite(newLED2.addr , LOW);    // set the LED off
  digitalWrite(newLED1.addr , HIGH);   // set the LED on
  delay(1000);              // wait for a second
}