const int mode_pin = 12; // SPARE PIN AVAILABLE
int Mode = 0;

void setup()
{               
	if(digitalRead(mode_pin) == 1)
	{
		Mode = 1;
	}
	else
	{
		Mode = 0;
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