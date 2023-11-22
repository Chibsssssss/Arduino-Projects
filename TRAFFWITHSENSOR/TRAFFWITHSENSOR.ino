// Define the pins for the traffic light LEDs
const int redNorthSouthPin = 5;
const int yellowNorthSouthPin = 6;
const int greenNorthSouthPin = 7;
const int switchNorthSouthPin = 0; // Pin for the switch

const int redEastWestPin = 2;
const int yellowEastWestPin = 3;
const int greenEastWestPin = 4;
const int switchEastWestPin = 1; // Pin for the switch

// Define the time (in milliseconds) for each traffic light state
const unsigned long redLightTime = 5000;     // 5 seconds
const unsigned long yellowLightTime = 2000;  // 2 seconds
const unsigned long greenLightTime = 5000;   // 5 seconds

// Flags to determine the control mode
bool switchControlMode = false;

void setup() {
  // Initialize the LED pins as output
  pinMode(redNorthSouthPin, OUTPUT);
  pinMode(yellowNorthSouthPin, OUTPUT);
  pinMode(greenNorthSouthPin, OUTPUT);
  
  pinMode(redEastWestPin, OUTPUT);
  pinMode(yellowEastWestPin, OUTPUT);
  pinMode(greenEastWestPin, OUTPUT);
  
  // Initialize the switch pins as input with internal pull-up resistors
  pinMode(switchNorthSouthPin, INPUT_PULLUP);
  pinMode(switchEastWestPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the switches
  int northSouthSwitchState = digitalRead(switchNorthSouthPin);
  int eastWestSwitchState = digitalRead(switchEastWestPin);
  
  // If both switches are HIGH, use the traffic light sequence (first code)
  if (northSouthSwitchState == HIGH && eastWestSwitchState == HIGH) {
    switchControlMode = false;

    // Traffic Light Sequence
    digitalWrite(redNorthSouthPin, HIGH);
    digitalWrite(greenEastWestPin, HIGH);
    delay(greenLightTime);
    
    digitalWrite(greenEastWestPin, LOW);
    digitalWrite(yellowEastWestPin, HIGH);
    delay(yellowLightTime);
    
    digitalWrite(yellowEastWestPin, LOW);
    digitalWrite(redEastWestPin, HIGH);
    digitalWrite(greenNorthSouthPin, HIGH);
    delay(greenLightTime);
    
    digitalWrite(greenNorthSouthPin, LOW);
    digitalWrite(yellowNorthSouthPin, HIGH);
    delay(yellowLightTime);
    
    digitalWrite(yellowNorthSouthPin, LOW);
    digitalWrite(redNorthSouthPin, HIGH);
  }
  // If only one of the switches is HIGH, use switch-based control (second code)
  else {
    switchControlMode = true;

    // Control the North-South Traffic Lights
    if (northSouthSwitchState == HIGH) {
      digitalWrite(greenNorthSouthPin, HIGH);
      digitalWrite(redNorthSouthPin, LOW);
    } else {
      digitalWrite(greenNorthSouthPin, LOW);
      digitalWrite(redNorthSouthPin, HIGH);
    }
    
    // Control the East-West Traffic Lights
    if (eastWestSwitchState == HIGH) {
      digitalWrite(greenEastWestPin, HIGH);
      digitalWrite(redEastWestPin, LOW);
    } else {
      digitalWrite(greenEastWestPin, LOW);
      digitalWrite(redEastWestPin, HIGH);
    }
  }
  
  // Add a short delay before updating the traffic light state again
  delay(yellowLightTime);
}
