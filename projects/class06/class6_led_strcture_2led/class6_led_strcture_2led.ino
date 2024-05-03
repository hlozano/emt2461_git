/*		structures */
 struct LED_t 
 {
   int addr;
   int status; // 0 for low 1 for high
 };
 
struct LED_t newLED1;
struct LED_t newLED2;


void setup()  
{                
  newLED1.addr = 13;
  pinMode(newLED1.addr, OUTPUT);  
  digitalWrite(newLED1.addr , LOW);    // set the LED off
  newLED1.status = 0;  
  
  newLED2.addr = 14;
  pinMode(newLED2.addr, OUTPUT);   
  digitalWrite(newLED1.addr , LOW);    // set the LED off
  newLED2.status = 0;  
}

void loop() 
{
  digitalWrite(newLED1.addr , HIGH);   // set the LED on
  newLED1.status = 1; 
  digitalWrite(newLED2.addr , LOW);    // set the LED off
  newLED2.status = 0; 
  delay(1000);              // wait for a second
  
  digitalWrite(newLED1.addr , LOW);    // set the LED off
  newLED1.status = 0; 
  digitalWrite(newLED2.addr , HIGH);   // set the LED on
  newLED2.status = 1; 
  
  delay(1000);              // wait for a second
}