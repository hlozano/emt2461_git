const int mode_pin = 12; // SPARE PIN AVAILABLE
int Mode = 0;

void setup()
{         
	pinMode(mode_pin, INPUT_PULLUP);      
	if(digitalRead(mode_pin) == 1)
	{//by default it will go here with no connections
		Mode = 1;
	}
	else
	{// you will need to connect a jumper between ground and mode_pin
		Mode = 2;
	}    
}
void loop()
{
	timers();
	checkdistance();
	checktemperature();
	
	if(Mode == 1)
		control_program_1(); // for example : wall avoider
	else
		control_program_2(); // for example : bluetooth driven

}