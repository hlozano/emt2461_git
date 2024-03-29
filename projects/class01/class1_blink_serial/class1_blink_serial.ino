/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
  
  millis() returns a long value that represents the number of milliseconds 
  the MCU has been running
 */
#define LEDpin 13
void setup()
{                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(LEDpin, OUTPUT);   
  Serial.begin(9600);  // you need to pass on the BAUD rate

  /*defition from google
  Baud, or baud rate, is used to describe the maximum oscillation 
  rate of an electronic signal. For example, if a signal 
  changes (or could change) 1200 times in one second, 
  it would be measured at 1200 baud.
  */
}

void loop()
{
  int time_running = 0;
  digitalWrite(LEDpin, HIGH);   // set the LED on
  Serial.println("LED is HIGH");
	delay(1000);              // wait for a second
	digitalWrite(LEDpin, LOW);    // set the LED off
  Serial.println("LED is LOW");
	delay(1000);              // wait for a second
  time_running = millis(); // similar "micros()"
  Serial.println(time_running);// time that has passed 
							 //up to the this point
}



/*
millis() and micros() are built in functions 
of the arduino that give me the run time of the 
MCU in the corresponding units
*/
