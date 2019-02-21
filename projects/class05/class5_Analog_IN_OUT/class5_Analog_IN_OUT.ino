int ledPin = 9;      // LED connected to digital pin 9
int analogPin = 3;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value
/*
Syntax
analogWrite(pin, value)
Parameters
pin: the pin to write to.
value: the duty cycle: between 0 (always off) and 255 (always on).
*/
void setup()
{
  Serial.begin(9600);          //  setup serial
  pinMode(ledPin, OUTPUT);   // sets the pin as output
}
void loop()
{
  val = analogRead(analogPin);   // read the input pin
  //if value is 1007.... then the output will be 1007 / 4 = 251
  analogWrite(ledPin, val / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  Serial.println('analog input = ',val);  // debug value
  Serial.println('analog output = ',val / 4);  // debug value
  delay(1000);
}
