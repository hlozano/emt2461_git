/*very basic program to simulate a basic elevator that is manually controlled to run or stop
the controlling here is done by a serial port*/

/*    INTRO TO FINITE STATE MACHINES    */
int state = 0;
int goup_cmd = 0;
int godn_cmd = 0;
int stop_cmd = 0;

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES  

unsigned long up_led_tmr = 0;       // up_led_tmr     is incremented every 100ms = 0.1s
unsigned long dn_led_tmr = 0;       // dn_led_tmr     is incremented every 100ms = 0.1s
unsigned long printing_tmr = 0;     // printing_tmr is incremented every 100ms = 0.1s
const int up_led_pin = 12;
const int dn_led_pin = 13;
int inByte;

void timers(void);
void receive_serial(void);
void transmit_serial(void);
void elevator_control(void);
void clear_commands(void);
void flash_up_led(void);
void flash_dn_led(void);
void motor_stop(void);
void motor_run_up(void);
void motor_run_dn(void);


void turn_on_leds(void)
{
  digitalWrite(up_led_pin,HIGH);
  digitalWrite(dn_led_pin,HIGH);
}

void turn_off_leds(void)
{
  digitalWrite(up_led_pin,LOW);
  digitalWrite(dn_led_pin,LOW);
}



void setup()
{               
  Serial.begin(9600); 
  pinMode(up_led_pin, OUTPUT);
  pinMode(dn_led_pin, OUTPUT);
}
void loop()
{
  timers();
  elevator_control();
  receive_serial();
  transmit_serial();
}

void clear_commands(void)
{
  goup_cmd = 0;
  godn_cmd = 0;
  stop_cmd = 0; 
}
void elevator_control(void)
{
  switch(state)
  {
    case 0: //STOP
      motor_stop();
      turn_off_leds();    
      if(goup_cmd == 1)
        state = 1;
      else if(godn_cmd == 1)
        state = 2;
      break;  
    case 1: // RUN UP STATE 
      motor_run_up();
      flash_up_led();
      if(stop_cmd == 1)
        state = 0;
      break;  
    case 2: // RUN DOWN STATE
      motor_run_dn();
      flash_dn_led();
      if(stop_cmd == 1)
        state = 0;
      break;  
    default: 
      state = 0;
      break;
  }
  clear_commands(); 
}

void receive_serial(void)
{ static int command; 
  
  if (Serial.available() > 0) 
  {
    inByte = Serial.read();
    Serial.println(inByte);
    //Serial.println("GOT IT!");
    command = inByte;
  

    switch (command)
    {
      case 'u': 
        goup_cmd = 1;
        break;
      case 'd': 
        godn_cmd = 1;
        break;
      case 's': 
        stop_cmd = 1;
        break;
      default:
        Serial.println("Unrecognized command :/");
        break;
    } 
  
  }
}


void transmit_serial(void)
{
  if(printing_tmr < 20) // 2 seconds
    return;


  printing_tmr = 0;

  switch (state)
  {
    case 0: 
      Serial.println("Elevator stopped");
      break;
    case 1: 
      Serial.println("Elevator going up");
      break;
    case 2: 
      Serial.println("Elevator going down");
      break;
    default:
      Serial.println("Unrecognized state :/");
  }

}


void flash_up_led() 
{
  if(up_led_tmr<5)      //first 10 (10 times 100 ms = 1s)
    digitalWrite(up_led_pin,HIGH); 
  else
  {
    digitalWrite(up_led_pin,LOW);
    if(up_led_tmr>=10) //(between 10 and 20 - another 1 s)
      up_led_tmr = 0; //When does the timer get cleared?
  }
}
void flash_dn_led() 
{
  if(dn_led_tmr<5)      //first 10 (10 times 100 ms = 1s)
    digitalWrite(dn_led_pin,HIGH); 
  else
  {
    digitalWrite(dn_led_pin,LOW);
    if(dn_led_tmr>=10) //(between 10 and 20 - another 1 s)
      dn_led_tmr = 0; //When does the timer get cleared?
  }
}

void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
    millis_old = millis_old + interval;
    up_led_tmr++;
    dn_led_tmr++;
    printing_tmr++;
  }
  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  
}



void motor_stop()
{

}
void motor_run_up()
{

}
void motor_run_dn()
{

}
