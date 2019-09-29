/*		
		class4_EEPROM_read_write.c
		Edited by H. Lozano
 
 EEPROM Read/Write
 -----------------
 Reads the value of address in EEPROM 
 Increments the value by one and writes it back
 
 This program keeps a count of how many times the MCU
 has been powered up. It works well up to 255 (one byte).
 */

#include <EEPROM.h>	//  <------- some options require adding libraries to your projects

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte myvariable = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  // read a byte from the current address of the EEPROM
    for (address = 0; address < 99; ++address)
    {
      myvariable = EEPROM.read(address);
      Serial.print(" memory location ");
      Serial.print(address);
      Serial.print("   contains ");
      Serial.print(myvariable);
      Serial.println();     
    }

	//for(;;);
  while(1)
  {
  
  };
}