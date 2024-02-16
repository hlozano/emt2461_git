//lab1 - program#1

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
	if(digitalRead(USER_BUTTON_INPUT) == 1) 
    {
      	Serial.println("Input High");
		state = 1;
    }
	else
    {
      	Serial.println("Input Low");
		state = 0;
    }

	//execute commands based on state	
	if (state == 1)
		digitalWrite(USER_LED_OUTPUT, HIGH); 
	else
		digitalWrite(USER_LED_OUTPUT, LOW);
	
	//monitor and print changes of state
	//if(old_state != state)
  	if(0)
	{
		counter++;
		Serial.print("counter = ");
		Serial.println(counter);
		old_state = state;
	}
}





