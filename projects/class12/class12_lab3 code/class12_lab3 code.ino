#include <Servo.h>
int val = 0, pos = 0, current_pos = 0;
int analogPin = A0;
Servo myservo;

//all timers are defined here
unsigned long timer1 = 0;
unsigned long timer2 = 0;


void timers(void);

void setup() 
{
  myservo.attach(3);
  Serial.begin(9600);
}
void loop() 
{
  timers();
  val = analogRead(analogPin);
  pos = map(val, 0, 1023, 0, 180);
  if (pos != current_pos)
    myservo.write(pos); //
  current_pos = pos;

  if(timer1 >= 10)
  {
    Serial.println("Position (angle in degree) = ");
    Serial.print(pos);
    Serial.print("\t Read Value (from an analog input) = ");
    Serial.println(val);
    Serial.print("t1=");
    Serial.println(timer1);    
    timer1 = 0;
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
  }
  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  
}
