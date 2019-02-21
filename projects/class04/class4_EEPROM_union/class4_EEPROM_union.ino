x`/*
 * EEPROM Read
 *
 * Reads the value of each byte of the EEPROM and prints it 
 * to the computer.
 * This example code is in the public domain.
 */
#include <EEPROM.h>
// start reading from the first byte (ee_address 0) of the EEPROM
unsigned int ee_address = 0;
byte value = 0;
/*
Description
Unsigned long variables are extended size variables for number storage,
and store 32 bits (4 bytes). Unlike standard longs unsigned longs won't 
store negative numbers, making their range from 0 to 4,294,967,295 (2^32 - 1)
*/
static union {
		unsigned char mylb[4];		// 4- 8 bit bytes (I could have used data type "byte")
		unsigned long int myll;			// 1-32 bit word
	};

	/* same as defining 
static union {
		byte mylb[4];		// 4- 8 bit bytes (I could have used data type "byte")
		unsigned long int myll;			// 1-32 bit word
	};
	*/


void setup()
{		//if data is initialized we will have a 56 in first location (our choice)
	Serial.begin(9600);
	ee_address = 0;
	value = EEPROM.read(ee_address);
	if(value != 101)	// Memory was not initialized
	{
		Serial.println("data was not initialized");
		EEPROM.write(ee_address,101); // make sure I leave a mark knowing I was here
		myll = 4000000000; // 4 billions
		ee_address++;
		EEPROM.write(ee_address,mylb[0]);
		ee_address++;
		EEPROM.write(ee_address,mylb[1]);
		ee_address++;
		EEPROM.write(ee_address,mylb[2]);
		ee_address++;
		EEPROM.write(ee_address,mylb[3]);
		Serial.println("data was NOT initialized. We saved a 101 in ee_adress 0");
		while(1);//intentional
	}
	else
		Serial.println("data was already initialized. We read a 101 in ee_adress 0");	
}

void loop()
{
	ee_address = 0;
	//READ MEMORY
	value = EEPROM.read(ee_address);
	ee_address++;
	mylb[0] = EEPROM.read(ee_address); // ee_address 1
	ee_address++;
	mylb[1] = EEPROM.read(ee_address); //ee_address 2
	ee_address++;
	mylb[2] = EEPROM.read(ee_address);//ee_address 3
	ee_address++;
	mylb[3] = EEPROM.read(ee_address);//ee_address 4
	//at this point myll has the data that
	//was previousky saved.... 4 000 000 000 (first time)
	myll++; // SAME AS THE OTHER PROGRAM WHEN WE DID ... value++

	Serial.print(ee_address);
	Serial.print("\t");
	Serial.print(value, DEC);
	Serial.println();
	
	Serial.print(ee_address);
	Serial.print("\t");
	Serial.print(myll, DEC);
	Serial.println();

	ee_address = 1;
	EEPROM.write(ee_address,mylb[0]);
	ee_address++;
	EEPROM.write(ee_address,mylb[1]);
	ee_address++;
	EEPROM.write(ee_address,mylb[2]);
	ee_address++;
	EEPROM.write(ee_address,mylb[3]);	
	

	while(1) // locks the program
	{
		//program never leaves
	}

}

/* Additional study

there are two places in the code where 
the program is locked in an infinite loop.

Program a specific LED flashing pattern in 
each of these infinite loops to distinguish 
where the program ends 




*/