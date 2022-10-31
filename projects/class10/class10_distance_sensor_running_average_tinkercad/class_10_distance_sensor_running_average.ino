// tested in tinkercad on 4/29/0222

int cm = 0;
int D_cm_average = 0;
int old_D_cm_average = 0;
const int nmb_samples = 10;

long readUltrasonicDistance(int triggerPin, int echoPin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  old_D_cm_average = D_cm_average;
  D_cm_average = (nmb_samples * old_D_cm_average - old_D_cm_average + cm)/nmb_samples;
  
  Serial.println(D_cm_average);
  //Serial.println(cm);
  delay(100); // Wait for 100 millisecond(s)
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
