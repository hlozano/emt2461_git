	// CALCULATE LOOP CYCLE USING A COUNTER - Works for over a month
unsigned long counter = 0;
unsigned long int timer1;
void setup()
{
    Serial.begin(9600);
}
void loop()
{
	static unsigned long millis_old = 0; // record the # ms the mcu has been running
	static unsigned long one_ms_timer = 0; //will help me track one ms intervals
								// this one keeps track of one ms intervals
								// it changes from 0 -> 999

    counter++;
    if(millis() > millis_old)
	{//it falls into this section once every 1ms
		millis_old = millis();
		one_ms_timer++; //one_ms_timer++;  
	}

	if(one_ms_timer>=1000)     // meaning every 1s
	{	
		timer1++;
		one_ms_timer = 0;
		Serial.print("counter  ");
        Serial.println(counter);

        Serial.print("millis() returns  ");
        Serial.println(millis());

		counter = 0;
	}
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
