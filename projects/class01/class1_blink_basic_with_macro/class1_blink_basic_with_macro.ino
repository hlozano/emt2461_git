
// statement above is equivalent to the following macro below (#define... statements are called macros)
// both strategies help not to write the number 13 everywhere we want to
// refer to this specific pin.

//option 1
//#define LED_pin 13 // best method
//means find LED_pin and replace with 13 before compiling
//using  macro will do a find a replace before the compiler is called in
//this is done by the precompiler
//after all the instances are replaced, the compiler will be invoked



//option 2
// int LED_pin = 13; // it requries additional memory,
					 //it may change in execution time
// const int LED_pin = 13;
//const prefix is optional
// it helps ensure no one will
// change its value in execution time



//using a macro
// #define LED_pin 13
// #define LED_Toggle_Delay 1000
//OR a definition
const int LED_pin = 3;
const int LED_Toggle_Delay = 1000;

void setup()
{ 
  pinMode(LED_pin,OUTPUT);
}
void loop()
{
	
   digitalWrite(LED_pin,HIGH);
   delay(LED_Toggle_Delay);
   digitalWrite(LED_pin,LOW);
   delay(LED_Toggle_Delay);
}



/* advanced macros
c precompiler allows you to 
use macros in ways that 
ressemble a function.
It works as if it is a function

//good macro 
#define SQUARE(x) ((x)*(x))

the following example is a bad definition of a square
//bad macro
#define SQUARE(x) (x * x)
it is bad because if you have the following code:

square(4+1);

based on the bad macro definition i.e. (x*x)
square(3+2)   ->  (3+2 * 3+2) -> (3 + 6 + 2) -> (11)

based on the good macro definition i.e. ((x)*(x))
square(3+2)   ->  ((3+2)*(3+2)) ->  ((5)*(5))  -> (25)


(/)












