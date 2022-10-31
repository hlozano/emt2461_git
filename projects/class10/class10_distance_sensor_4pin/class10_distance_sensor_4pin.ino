#include<NewPing.h>

#define  TRIGGER_PIN  8
#define  ECHO_PIN     7
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int DistanceIn;
int DistanceCm;
void setup()
{
    Serial.begin(9600); 

}
void loop()
{
    DistanceIn = sonar.ping_in();
    Serial.print("Ping: ");
    Serial.print(DistanceIn); // Convert ping time to distance and print result 
                              // (0 = outside set distance range, no ping echo)
    Serial.print(" in     ");
    
    delay(100);// Wait 100ms between pings (about 10 pings/sec). 29ms should be the shortest delay between pings.
    DistanceCm = sonar.ping_cm();
    Serial.print("Ping: ");
    Serial.print(DistanceCm); 
    Serial.println(" cm"); 
}

