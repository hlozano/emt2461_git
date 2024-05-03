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


	timers();
	checkdistance();
	checktemperature();

	check_mode_of_operation();
	
	if(Mode == 1)
		control_program_1(); // for example : Auto
	else if (Mode == 2)
		control_program_2(); // for example : Manual
	else
		control_program_0(); // for example : OFF



}

void check_mode_of_operation(void)
{
	static int previous_Mode = 0;
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
	if (previous_Mode != Mode)
	{
		reset_all_systems();
		previous_Mode = Mode;
	}
}

void reset_all_systems(void)
{//Make sure all your systems are 
// set to off so nothing is being driven 

}