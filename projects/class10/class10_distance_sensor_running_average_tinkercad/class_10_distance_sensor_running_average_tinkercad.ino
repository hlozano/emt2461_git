// tested in tinkercad on 4/29/0222

int cm = 0;
int D_cm_average = 0;
int old_D_cm_average = 0;
const int nmb_samples = 20;

long readUltrasonicDistance(int triggerPin, int echoPin);

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
unsigned long check_distance_timer; // timer1 is incremented every 100ms = 0.1s
unsigned long heartbeat_timer; // timer1 is incremented every 100ms = 0.1s

void timers(void);
void check_distance(void);
void heartbeat_led(void);
  const int LED1 = 13;

void setup()
{

  pinMode(LED1, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  timers();
  check_distance();
  heartbeat_led();

}
void heartbeat_led(void)
{
  if(heartbeat_timer < 10)      //first 10 (10 times 100 ms = 1s)
    digitalWrite(LED1,HIGH); 
  else
    digitalWrite(LED1,LOW);
      
  if(heartbeat_timer>=20) //(between 10 and 20 - another 1 s)
    heartbeat_timer = 0;  //When does the timer get cleared?  
}

void check_distance(void)
{
  if (check_distance_timer >= 1)
  {
    check_distance_timer = 0;
    cm = 0.01723 * readUltrasonicDistance(7, 7);
    old_D_cm_average = D_cm_average;
    D_cm_average = (nmb_samples * old_D_cm_average - old_D_cm_average + cm)/nmb_samples;
    Serial.println(D_cm_average);
  }
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void timers(void)
{
  static unsigned long ms_runtime;
  static int one_ms_timer;

  if(millis() > ms_runtime)
  { ms_runtime++;
    one_ms_timer++;  
  }
  else if(ms_runtime > millis())
    ms_runtime = millis();

  if(one_ms_timer > 99)
  { timer1++;
        check_distance_timer++;
        heartbeat_timer++;
    one_ms_timer = 0;
  }

}
