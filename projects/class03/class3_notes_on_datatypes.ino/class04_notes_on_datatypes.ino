unsigned short int my_sint = 0;
unsigned int my_uint = 0;
unsigned long int my_ulongint = 0;
unsigned char my_uchar = 0;


void setup() 
{
  Serial.begin(9600);  // you need to pass on the BAUD rate
}

void loop() 
{
  Serial.println("printing the range for unsigned short int");
  Serial.println(my_sint);
  my_sint = my_sint - 1;
  Serial.println(my_sint);

  Serial.println("printing the range for unsigned int");
  Serial.println(my_uint);
  my_uint = my_uint - 1;
  Serial.println(my_uint);

  Serial.println("printing the range for unsigned long int");
  Serial.println(my_ulongint);
  my_ulongint = my_ulongint - 1;
  Serial.println(my_ulongint);

  Serial.println("printing the range for unsigned char");
  Serial.println(my_uchar);
  my_uchar = my_uchar - 1;
  Serial.println(my_uchar);
  while(1);

}