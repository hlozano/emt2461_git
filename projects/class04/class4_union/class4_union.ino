
static union {
    unsigned char mybytes[2];   // 2 - 8 bit bytes (We could use data type "byte")
    unsigned int myinteger;       // 1 - 16 bit word
  };



void setup()
{   //if data is initialized we will have a 99 in first location (our choice)

   // added delay so the first time we program
   // the board we see the sequence play out 
  delay(2000);
  Serial.begin(9600);


}

void loop()
{
  mybytes[1] = 2;
  Serial.print("-------mybytes[1] = 2--------");
  Serial.print("myinteger changes ------------");
  Serial.print(myinteger, DEC);
  Serial.println();
  Serial.print("------------------------------");
  Serial.println();

  

  Serial.println();
  myinteger=2064;
   Serial.println("myinteger= 2064 and then");
  Serial.print("   mybytes[0]= ");
  Serial.println(mybytes[0], DEC); 
  Serial.print("   mybytes[1]= ");
  Serial.print(mybytes[1], DEC);


  
  

  while(1) // locks the program
  {
    //program never leaves
  }

}
