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
  static unsigned long ms_runtime;
  static int one_ms_timer;

  if(millis() > ms_runtime)
  {
    ms_runtime++;
    one_ms_timer++;  
  }
  else if( ms_runtime > millis())
    ms_runtime = millis();

  if(one_ms_timer> 99) // every 100 ms
  {
    timer1++;
    timer2++;
    one_ms_timer= 0;
  }
}
