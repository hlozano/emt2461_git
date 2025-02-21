//lab1 - program#1
#define BUTTON_PRESSED 0 // input pullup reads 0 when pressed
#define BUTTON_RELEASED 1

const int USER_LED_OUTPUT = 13;
const int USER_BUTTON_INPUT = 2;



void setup()
{ // initialize io pins and serial port               
	pinMode(USER_LED_OUTPUT, OUTPUT);     
	pinMode(USER_BUTTON_INPUT, INPUT_PULLUP);
	Serial.begin(9600);
}
void loop()
{	//run loop forever
	static int state,old_state,counter;
	//logic for state change
  	
	if(digitalRead(USER_BUTTON_INPUT) == BUTTON_PRESSED) 
    {
    	state = 1;
    }
	if (digitalRead(USER_BUTTON_INPUT) == BUTTON_RELEASED)
    {
    	state = 0;
    }
    

	//execute commands based on state	
	if (state == 1)
		digitalWrite(USER_LED_OUTPUT, HIGH); 
	else
		digitalWrite(USER_LED_OUTPUT, LOW);
	
	//monitor and print changes of state
	if(old_state != state)
	{
		counter++;
		Serial.print("counter = ");
		Serial.println(counter);
		old_state = state;
	}
}





