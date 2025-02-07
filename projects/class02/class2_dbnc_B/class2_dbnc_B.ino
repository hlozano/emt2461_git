const int LED1 = 13;
const int buttonPin = 2;

/*	I refer to this method as the google* way.
	* meaning an online search result for newbies - cheap and unreliable.
	Before doing this program we did a very rough calculation of a different program
	and determined that the loop time for that program was about ~20 us (microseconds)
*/
void setup()
{  // initialize the digital pin as an output.
	pinMode(LED1, OUTPUT);     
	pinMode(buttonPin, INPUT);
}
void loop()
{
	static int button_dbnc; // remember that this is the same as having
							// a global variable meaning the value of the
							// variabe will be preserved as you leave and
							// reenter this function. Scope: local*
	if(digitalRead(buttonPin) == 1) 
	{
		if(button_dbnc > 33000) //if loop time is 27us...
		{ // then led turns on after..... 33000x27us aprox. 1s (Actually .891 sec)
			digitalWrite(LED1, HIGH); 
		}
		button_dbnc++;
	}
	else
	{
		digitalWrite(LED1, LOW);
		button_dbnc = 0;
	} 
}
/*
	What will happen if we increase the size of our program???

	
	Conclusion: __________________________________
*/





