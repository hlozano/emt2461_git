/*
  micros() returns a long value that represents the number of microseconds 
  the MCU has been running
*/
  /*Global scope vs local scope*/

unsigned int counter = 0;
unsigned long time = 0;   // this wont interfere with any local variables called time
unsigned long old_time = 0;
int tpm = 0;

void myfunction(void);

void setup()
{
  unsigned long time;// this wont interfere with the variable defined in loop
  Serial.begin(9600);
}
void loop()
{
  unsigned long time; 
  int special_var;		//variable with local scope

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
    Serial.println(special_var);
  }
}

void myfunction()
{// this is a really pointless function that executes 1000 insructions
  int i;
  for(i = 0;i<=1000;i++)//<---- play with this number
    tpm = tpm + 1;
}


/*
when this program is run using N iterations inside myfunction() it yields a loop time of____


N		Loop time
1000	254 us
2000	507 us
3000	760 us



*/
