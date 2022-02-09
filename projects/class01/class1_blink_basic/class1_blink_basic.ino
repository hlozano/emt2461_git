void setup()
{ 
  pinMode(13,OUTPUT);
}
// loop
void loop()
{// loop
   digitalWrite(13,HIGH); // 5V
   delay(1000);
   digitalWrite(13,LOW); // 0V
   delay(1000);
}


/*
in normal c programming you have
int main()
{

}
//arduino did this to make things 
//'easier' on programmers
int main()
{
	setup();
	while(1) //loop based on a condition
	{
		loop();
	}
}
*/

void another_function(void)
{

}