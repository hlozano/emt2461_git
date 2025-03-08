#include "myled.h"

LED newLED1(13);

void setup() 
{                

}

void loop() 
{
  newLED1.toggle();
  delay(1000);              
}  
