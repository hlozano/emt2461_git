/*    class3_basics_while.c

This program illustrates:
  how to use while loops
  while safety mechanism using safe_count variable
  what happens with for(;;);
*/
int numbers[10];
void setup()
{
  int i = 0;
  Serial.begin(9600);
  while( i < 10)
  {
    numbers[i] = i;
    Serial.println(i);
    delay(500);
    i++;
  }
  Serial.print("done with my 1st while loop");
}
void loop()
{
  int i = 0;
  int safe_count = 0;

  safe_count = 0;
  while(( i < 10) && (safe_count < 1000))
  {
    safe_count++;
    Serial.println(numbers[i]);
    delay(500);
    i++;
  }
  Serial.print("done with my 2nd while loop");
  while(1); // lock program forever
}


/*  while(i = 1)
  {

  } //force the program to go in an infinite loop.
there is nothing wrong with the statement i = 1. 
It is a velid statement and it always returns true

*/






