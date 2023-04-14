#define AIN1 7
#define BIN1 8
#define PWMA 5   //motor pins
#define PWMB 6
#define STBY 3
#define Speed 200

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
const int LED1 = 13;
int inByte;

void timers(void);
void forword(void);
void backword(void);
void turnRight(void);
void turnLeft(void);
void Stop(void);

void setup()
{               
  Serial.begin(9600); 
  pinMode(LED1, OUTPUT);  

  pinMode(PWMA, OUTPUT); // declare as output for L298 Pin enA
  pinMode(AIN1, OUTPUT); // declare as output for L298 Pin in1
  pinMode(BIN1, OUTPUT); // declare as output for L298 Pin in2 
  pinMode(STBY, OUTPUT); // declare as output for L298 Pin in4
  pinMode(PWMB, OUTPUT); // declare as output for L298 Pin enB
 
 
}
void loop()
{
    static int command; 
    timers();
  if (Serial.available() > 0) 
  {
    inByte = Serial.read();
    command = inByte;
  }


  switch (command)
  {
    case '0': 
      Stop();
      break;
    case '1': 
      forword();
      break;
    case '2': 
      backword();
      break;
    case '3': 
      turnLeft();
      break;
    case '4': 
      turnRight();
      break;
    case '5': 
      Stop();
      break;
    default:
      
  }

  if (command != 5) and (command != 0)
  {
    analogWrite(PWMA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
    analogWrite(PWMB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed
  }
  else
  {
    analogWrite(PWMA, 0); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
    analogWrite(PWMB, 0); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed    
  }
}



 

void forword()
{  //forword
  digitalWrite(AIN1, HIGH); //Right Motor forword Pin
  digitalWrite(BIN1, LOW);  //Right Motor backword Pin
  digitalWrite(STBY, HIGH);  //Right Motor backword Pin 
}

 

void backword()
{ //backword

  digitalWrite(AIN1, LOW);  //Right Motor forword Pin
  digitalWrite(BIN1, HIGH); //Right Motor backword Pin
  digitalWrite(STBY, HIGH);  //Right Motor backword Pin
}

 

void turnRight()
{ //turnRight

  digitalWrite(AIN1, LOW);  //Right Motor forword Pin
  digitalWrite(BIN1, HIGH); //Right Motor backword Pin
  digitalWrite(STBY, HIGH);  //Right Motor backword Pin 
}

 

void turnLeft()
{ //turnLeft

  digitalWrite(AIN1, HIGH); //Right Motor forword Pin
  digitalWrite(BIN1, LOW);  //Right Motor backword Pin
  digitalWrite(STBY, HIGH);  //Right Motor backword Pin
}

void Stop()
{ //stop

  digitalWrite(AIN1, LOW); //Right Motor forword Pin
  digitalWrite(BIN1, LOW); //Right Motor backword Pin
  digitalWrite(STBY, LOW); //OUTPUTS DISABLE
}

void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100s
    millis_old = millis_old + interval;
    timer1++;
  }
  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  
}
