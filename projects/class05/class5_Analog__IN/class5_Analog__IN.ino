/* read analog input sample program*/

int analogPin = A3;     // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V


int val = 0;           // variable to store the value read

void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  val = analogRead(analogPin);    // read the input pin
  Serial.println(val);  // debug value
  delay(1000);
}

/*
To calculate resolution.... res = 5Vdc/1024 = 4.9mV
*/