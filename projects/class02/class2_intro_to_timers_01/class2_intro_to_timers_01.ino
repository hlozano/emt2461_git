// CALCULATE LOOP CYCLE USING A COUNTER - Works for over a month
unsigned long ms_runtime = 0; // record the # ms the mcu has been running
unsigned long one_ms_timer = 0; //will help me track one ms intervals
								// this one keeps track of one ms intervals
								// it changes from 0 -> 999
unsigned long counter = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    counter++;
    if(millis() > ms_runtime)
	{
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}
	if(one_ms_timer>=1000)
	{// 1000 times one ms means we go in this section every 1sec
		one_ms_timer = 0;
		Serial.print("counter  ");
        Serial.println(counter);
		counter = 0;
	}
}
