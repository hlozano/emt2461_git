
int motorPin = 3;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, 0);
  Serial.begin(9600);		// classes
}
void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <= '9')
    //same as saying (byte) ch > 48 && ch <= 57
    {
      //possible values of char at this point: 48d -> 57
      // int speed_level = ch - '0'; // gives me a number btw 0 and 9
      int speed_level = (int)ch - 48; // gives me a number btw 0 and 9
      int speed_value = speed_level * 28;
      //possible values of char at this point: 0d  -> 9d
      analogWrite(motorPin, speed_value);
      // speed_level used in calculation above 0  ->  252
      if(ch >= '0' && ch <= '5')
        digitalWrite(13,HIGH);
      else
        digitalWrite(13,LOW);
    }
  }
}

//from ascii table
// dec  hex   char
// 48   30    0
// 49   31    1
// 50   32    2
// 51   33    3
// 52   34    4
// 53   35    5
// 54   36    6
// 55   37    7
// 56   38    8
// 57   39    9
 
