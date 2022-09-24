const int LED1 = 13;
const int buttonPin = 2;
/*
	This actually has no debouncing built into the reaction of the program 
	Every time the input is seen as high the output will turn on. However, 
	depending on the quality of the switch, it may bounce back and forth 
	hundreds of times before stabilizing to be high. See link 
		http://upload.wikimedia.org/wikipedia/commons/a/ac/Bouncy_Switch.png
	for an oscilloscope reading of an input being activated.
*/
void setup()
{                  
	pinMode(LED1,OUTPUT);     
	pinMode(buttonPin, INPUT);
}

void loop()
{
	if(digitalRead(buttonPin) == 1) 
	{								// LED may flicker 100 times (or more) 
		digitalWrite(LED1, HIGH); 	//everytime the button gets pressed
	}
	else
	{
		digitalWrite(LED1, LOW);
	}
}

/*

//If using INPUT_PULLUP configuration

const int LED1 = 13;
const int buttonPin = 2;
#define PRESSED 0

void setup()
{  	pinMode(LED1,OUTPUT);     
	pinMode(buttonPin, INPUT_PULLUP);
}
void loop()
{   if(digitalRead(buttonPin) == PRESSED) 
	{								
		digitalWrite(LED1, HIGH); 
	}	
	else
	{
		digitalWrite(LED1, LOW);
	}
}

*/






