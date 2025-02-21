

const int USER_LED_OUTPUT = 13;
const int USER_BUTTON_INPUT = 2;

bool pullup_read_button_press(int pin);

bool pullup_read_button_press(int pin)
{
	if(digitalRead(pin) == 1)
		return 0;
	else
		return 1;
}
 
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
  	
	if(pullup_read_button_press(USER_BUTTON_INPUT) == 1) 
    {
    	state = 1;
    }
	if (pullup_read_button_press(USER_BUTTON_INPUT) == 0)
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





