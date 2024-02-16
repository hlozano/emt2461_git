/*
 * EEPROM Read
 * Reads value stored from EEPROM and prints it 
 * to the computer.
 */
#include <EEPROM.h>
// start reading from the first byte (ee_address 0) of the EEPROM
unsigned int ee_address = 0;
byte value = 0;
/*
* Description
* Unsigned int variablescan be used for number storage,
* and store 16 bits (2 bytes). Unlike standard int unsigned int won't 
* store negative numbers, making their range from 0 to 65535 (2^16 - 1)
*/
static union {
    unsigned char mybytes[2];   // 2 - 8 bit bytes (We could use data type "byte")
    unsigned int myinteger;       // 1 - 16 bit word
  };

//unsigned int another_integer;

// MAP OF EEPROM LOCATIONS
// ADD    data
// 0      bookmark or initializer
// 1      half of my number
// 2      half of my number 

void setup()
{   //if data is initialized we will have a 99 in first location (our choice)

   // added delay so the first time we program
   // the board we see the sequence play out 
  delay(2000);
  Serial.begin(9600);
  ee_address = 0;
  value = EEPROM.read(ee_address);
  if(value != 99) // Memory was not initialized
  {
    Serial.println("EEPROM was not initialized");
    EEPROM.write(ee_address,99); // make sure I leave a mark knowing I was here
    myinteger = 30000; // 30000
    ee_address = 1;
    EEPROM.write(ee_address,mybytes[0]);
    ee_address = 2;
    EEPROM.write(ee_address,mybytes[1]);

    Serial.println("EEPROM was NOT initialized. We saved a 99 in ee_adress 0, and 30,000 as my counter");
    while(1);//intentional
  }
  else
  {
    Serial.println("EEPROM was already initialized. We read a 99 in ee_adress 0");  
  }
}

void loop()
{
  ee_address = 0;
  //READ MEMORY
  value = EEPROM.read(ee_address);
  ee_address++;
  mybytes[0] = EEPROM.read(ee_address); // ee_address 1
  ee_address++;
  mybytes[1] = EEPROM.read(ee_address); //ee_address 2

  myinteger++; // SAME AS THE OTHER PROGRAM WHEN WE DID ... value++

  Serial.print("initialization value    ");
  Serial.print(value, DEC);
  Serial.println();
  
  Serial.print("stored value changed to      ");
  Serial.print(myinteger, DEC);
  Serial.println();

  ee_address = 1;
  EEPROM.write(ee_address,mybytes[0]);
  ee_address++;
  EEPROM.write(ee_address,mybytes[1]);

  Serial.print("saved");
  Serial.println();
  Serial.print("------------------------------");
  Serial.println();
  

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