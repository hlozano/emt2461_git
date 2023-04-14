/***** www.arduinopoint.com *****/
/***** Arduino Clap Switch *****/
int SoundSensor=2; // LM393 Sound Sensor Digital Pin D0 connected to pin 2
int LED=3; // LED connected to pin 3
boolean oldSensorData=false;
int clapping_sequence = 0;
int clapping_command = 0;
int fan_state = 0;
int pos = 90;
int direction; //0=going up (CW)   1= going down (CCW)

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long timer2; // timer2 is incremented every 100ms = 0.1s
unsigned long timer3; // timer3 is incremented every 100ms = 0.1s

void setup() 
{
 pinMode(SoundSensor,INPUT);
 pinMode(LED,OUTPUT); 
 Serial.begin(9600); //initialize serial
}
void loop() 
{
  int SensorData=digitalRead(SoundSensor); 
  Serial.println(SensorData);//print the value

 control();

  timers();

  switch(clapping_sequence)
  {
        case 0:
            if(SensorData == 1)
            {
                clapping_sequence = 1;
                timer1 = 0;
            }
            break;
        case 1:
            if(timer1 >= 1)
            {
                if(SensorData == 1)
                {
                    clapping_sequence = 2;
                    timer1 = 0;
                }
            }
            break;
        case 2:
            if(timer1 >= 1)
            {
                if(SensorData == 1)
                {
                    clapping_sequence = 3;
                    timer1 = 0;
                }
            }
            break;
    }
    if (clapping_sequence == 0)
    {
        timer2 = 0;
    }
    else if (clapping_sequence != 0)
    {
        if(timer2 >= 30) // waiting for 2 seconds after first clap
        {
             clapping_command = clapping_sequence;
             clapping_sequence = 0;
        }   


    }



}

void control()
{

    switch(fan_state)
    {
        case 0:
            if(clapping_command == 1)
                fan_state = 1;
            else if(clapping_command == 2)
                fan_state = 2;
            else if(clapping_command == 3)
                fan_state = 3;
            break;
        case 1:
            if(clapping_command == 1)
                fan_state = 0;
            else if(clapping_command == 2)
                fan_state = 2;
            else if(clapping_command == 3)
                fan_state = 3;
            break;  
        case 2:
            if(clapping_command == 1)
                fan_state = 1;
            else if(clapping_command == 2)
                fan_state = 0;
            else if(clapping_command == 3)
                fan_state = 3;
            break;      
        case 3:
            if(clapping_command == 1)
                fan_state = 1;
            else if(clapping_command == 2)
                fan_state = 2;
            else if(clapping_command == 3)
                fan_state = 0;
            break;  

    }

    switch(fan_state)
    {
    case 0:
            //motors off
    break;
    case 1:
        //motor commands
        break;
    case 2:
        if(timer3 >= 1)  
        {
            timer3 = 0;
            if(direction == 0)
            {
                    pos = pos + 4;
            }
            if(direction == 1)
            {
                    pos = pos - 4;
            }    
        }    

        if (position == 180)
            direction = 1;
        if(position == 0)
            direction = 0;
            servo.write(position);
        break;
    case 3:
        break;

    }


}


void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
    millis_old = millis_old + interval;
    timer1++;
    timer2++;
    timer3++;
  }
  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  
}