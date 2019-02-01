/*
  micros() returns a long value that represents the number of microseconds 
  the MCU has been running
*/
  /*Global scope vs local scope*/

unsigned int counter = 0;
unsigned long time = 0;   // this wont interfere with any local variables called time
unsigned long old_time = 0;
int temp_integer = 0;

void myfunction(void);

void setup()
{
  unsigned long time;// this wont interfere with the variable defined in loop
  Serial.begin(9600);
}
void loop()
{
  unsigned long time; 
  int special_var = 1;    //variable with local scope

  counter++; // use counter to print only every 1000 times we go trhough loop.
  myfunction();   //experiment by adding and 
  if(counter >= 1000) 
  {
    special_var++;
    Serial.print("Loop Time=  ");
    time = micros();
    Serial.print((time - old_time)/counter);
    Serial.println("    microseconds");
    old_time = time;
    counter = 0;
    Serial.println("special variable");
    Serial.println( temp_integer / special_var);
  }
}

void myfunction()
{// this is a really pointless function that executes N insructions
  int i;
  int N = 1000;//<---- play with this number
  for(i = 1;i<=N;i++)
   // temp_integer = temp_integer + 1;//compiler too smart for this
    temp_integer = temp_integer + temp_integer % i;
}


/*
when this program is run using N iterations inside myfunction() it yields a loop time of____

N     Loop time
0001    55 us
0010    144 us
0100    1418 us ~ 1.4 ms
1000    14214 us ~ 14.214 ms


*/
