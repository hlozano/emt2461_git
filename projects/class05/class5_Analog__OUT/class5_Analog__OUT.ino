        // variable to store the read value
/*
Syntax
analogWrite(pin, value)
Parameters
pin: the pin to write to.
value: the duty cycle: between 0 (always off) and 255 (always on).
*/
const int ledPin = 9;      // LED connected to digital pin 9
int val = 0; 
void setup()
{
  Serial.begin(9600);          //  setup serial
  pinMode(ledPin, OUTPUT);   // sets the pin as output
}

void loop()
{
  analogWrite(ledPin, val); 
   value++; // same as value = value + 1
  if(value > 255)
  {
	value = 0;
  }
  delay(100);
}
