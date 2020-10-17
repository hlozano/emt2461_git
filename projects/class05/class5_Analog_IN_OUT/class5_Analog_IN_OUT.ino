/*
  This program outputs anlog voltage to pin9 of the Arduino 
  Voltage varies based on the input voltage on pin A3
*/
int LED_Analog_output_Pin = 9;
int analog_input_Pin = A3;

int input_value = 0;
int output_value = 0;

void setup()
{

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  Serial.begin(9600);
  input_value = analogRead(analog_input_Pin);
   
  Serial.print("input_value=");
  Serial.println(input_value);
  //if output_value is 1007.... then the output will be 1007 / 4 = 251
  output_value = input_value / 4;
  
  Serial.print("output_value=");
  Serial.println(output_value);
  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  analogWrite(LED_Analog_output_Pin, output_value);  

  delay(100); // Wait for 1000 millisecond(s)

}