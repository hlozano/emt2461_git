/* 
	class3_basics_for.c

This program illustrates:
	how to use for loops
	Scope review... what values are printed?
	what happens with for(;;);

*/

int temp = 0;
int i = 0;

void setup()
{
	int i=0;
    Serial.begin(9600);
   for (i=0; i <= 10; i++)
   {
      Serial.println(i);
      delay(10);
   }
}

void loop()
{
  	temp++; 		// 'unused' temp
	Serial.print(i);
	for(;;);		// lock the program forever
}



