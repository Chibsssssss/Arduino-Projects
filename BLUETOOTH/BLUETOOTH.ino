#include <SoftwareSerial.h>

// GPIO where relay is connected to
const int relayPin =  6;

// Handle received messages
String message = "";

// Create software serial object to communicate with HC-05
SoftwareSerial mySerial(3, 2); //HC-05 Tx & Rx is connected to Arduino #3 & #2

void setup() {
  // Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  // Initialize relayPin as an output
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  
  //Begin serial communication with Arduino and HC-05
  mySerial.begin(9600);

  Serial.println("Initializing...");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (mySerial.available()){
    char incomingChar = mySerial.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  if (message == "on"){
    digitalWrite(relayPin, LOW);
  }
  else if (message == "off"){
    digitalWrite(relayPin, HIGH);
  }
  delay(20);
}