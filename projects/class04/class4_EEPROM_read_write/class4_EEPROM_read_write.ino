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

#include <EEPROM.h> //  <------- some options require adding libraries to your projects

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte myvariable = 0;

void setup()
{
  Serial.begin(9600);
 
  myvariable = EEPROM.read(address);
  Serial.print("at first EEPROM memory location ");
  Serial.print(address);
  Serial.print("   contains ");
  Serial.print(myvariable);
  Serial.println();
  myvariable++;
  EEPROM.write(address,myvariable);
  Serial.println("then...");
  delay(2000);
}
void loop()
{
  // read a byte from the current address of the EEPROM
  myvariable = EEPROM.read(address);
 
  Serial.print(" memory location ");
  Serial.print(address);
  Serial.print("   contains ");
  Serial.print(myvariable);
  Serial.println();
  //for(;;);
  while(1)
  {
  
  };
  
}

/*  1
  0b 1000 1111
 +0b 1100 0000
 -------------
     0100 1111

*/
