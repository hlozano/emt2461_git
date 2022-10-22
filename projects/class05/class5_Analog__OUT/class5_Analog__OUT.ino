
/* Program to set the analog output */
/* Increases output to Max, then sets to zero and repeats*/


/*
Syntax
analogWrite(pin, value)
Parameters
pin: the pin to write to.
value: the duty cycle: between 0 (always off) and 255 (always on).
*/
const int ledPin = 9;      // LED connected to digital pin 9
int value = 0; 
void setup()
{
  Serial.begin(9600);          //  setup serial
  pinMode(ledPin, OUTPUT);   // sets the pin as output
}

void loop()
{

  for (value = 0; value <= 255; value += 2) {
    analogWrite(9, value);
    Serial.println(value);
    delay(30); // Wait for 30 millisecond(s)
  }
  for (value = 255; value >= 0; value -= 2) {
    analogWrite(9, value);
    Serial.println(value);
    delay(30); // Wait for 30 millisecond(s)
  }
}

