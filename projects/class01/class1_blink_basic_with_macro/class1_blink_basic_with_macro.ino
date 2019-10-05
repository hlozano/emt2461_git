
// statement above is equivalent to the following macro below (#define... statements are called macros)
// both strategies help not to write the number 13 everywhere we want to
// refer to this specific pin.


//#define LEDpin 13
// int LEDpin = 13; // ok thing to do but dangerous


//const prefix is optional
//it only helps ensure no one will
// change its value in execution time
//use a macro
//#define LEDpin 13
//OR a definition
const int LEDpin = 13;
const int LED_Blink_Rate = 1000;


void setup()
{ 
  pinMode(LEDpin,OUTPUT);
}
void loop()
{
	
   digitalWrite(LEDpin,HIGH);
   delay(LED_Blink_Rate);
   digitalWrite(LEDpin,LOW);
   delay(LED_Blink_Rate);
}















