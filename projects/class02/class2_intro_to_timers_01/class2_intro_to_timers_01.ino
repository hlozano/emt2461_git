	// CALCULATE LOOP CYCLE USING A COUNTER - Works for over a month
unsigned long counter = 0;
unsigned long int timer1;
void setup()
{
    Serial.begin(9600);
}
void loop()
{
	static unsigned long millis_old = 0;// track the # ms the mcu has been running
	static unsigned interval = 1000; 	// meaning every 1s

    counter++;

    if(millis() >= millis_old + interval)
	{//it falls into this section once every 1000ms
		millis_old = millis_old + interval;

		timer1++;
		Serial.print("counter  ");
        Serial.println(counter);

        Serial.print("millis() returns  ");
        Serial.println(millis());

		counter = 0;	
	}
	// else if(millis_old > millis())
	// { //if you run for a very long time, correct overflow
	// 	millis_old = millis();	
	// }

}

/* Special Note
pinted 
counter 248146
millis() returns 1000 ms

If we want to calculate loop time based on these numbers:


loop time = time interval / number of cycles

=1s / 248146

= 4.029 e-6 s = 4.029 us (microseconds!!!!!!)


*/
