// Pin where the LED is connected
const int ledPin = 12;  
const int ledPin2 = 13;  

// Interval at which to blink (milliseconds)
  


// Variables to store the current state of the LED and the last time it was updated
bool ledState = false;  
bool ledState2 = false;  


void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);  
  pinMode(ledPin2, OUTPUT);  
}

void blink_2()
{
  const long interval2 = 250;  
  static unsigned long previousMillis2 = 0;  
  unsigned long currentMillis2 = millis();
    if (currentMillis2 - previousMillis2 >= interval2) {
    // Save the last time you blinked the LED
    previousMillis2 = currentMillis2;   

    // If the LED is off, turn it on, and vice-versa
    ledState2 = !ledState2;

    // Set the LED to the ledState
    digitalWrite(ledPin2, ledState2);
}

void loop() {
  // Get the current time
  const long interval = 2000;
  static unsigned long previousMillis = 0;  
  unsigned long currentMillis = millis();
  // Check if the interval has passed
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you blinked the LED
    previousMillis = currentMillis;   

    // If the LED is off, turn it on, and vice-versa
    ledState = !ledState;

    // Set the LED to the ledState
    digitalWrite(ledPin, ledState);
  }

  blink_2();
}
