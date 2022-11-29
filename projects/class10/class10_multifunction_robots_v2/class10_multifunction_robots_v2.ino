const int mode0_pin = 10; // SPARE PIN AVAILABLE
const int mode1_pin = 11; // SPARE PIN AVAILABLE
const int mode2_pin = 12; // SPARE PIN AVAILABLE
int Mode = 0;

void setup()
{         
	pinMode(mode0_pin, INPUT_PULLUP);      
	pinMode(mode1_pin, INPUT_PULLUP);      
	pinMode(mode2_pin, INPUT_PULLUP);      
  
}
void loop()
{
	if(digitalRead(mode1_pin) == 0)
	{//by default it will go here with no connections
		Mode = 1;
	}
	else if (digitalRead(mode2_pin) == 0)
	{// you will need to connect a jumper between ground and mode_pin
		Mode = 2;
	}  
	else if (digitalRead(mode2_pin) == 0)
	{
		Mode = 0;
	}

	timers();
	checkdistance();
	checktemperature();
	
	if(Mode == 1)
		control_program_1(); // for example : Auto
	else if (Mode == 2)
		control_program_2(); // for example : Manual
	else
		control_program_0(); // for example : OFF
	else


}