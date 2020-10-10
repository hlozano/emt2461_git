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
	int i=0; // if we use a local var "i", the global "i" is not used here
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
	Serial.print("Loop prints ");
	Serial.println(i);
	for(;;);		// lock the program forever
}


/*
for loop reference from https://www.arduino.cc/reference/en/language/structure/control-structure/for/

initialization: happens first and exactly once.
condition: each time through the loop, condition is tested; if it’s true, the statement block, and the increment is executed, then the condition is tested again. When the condition becomes false, the loop ends.
increment: executed each time through the loop when condition is true.

*/