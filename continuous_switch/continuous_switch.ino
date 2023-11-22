int buttonPin = 5;  // the pin the button is connected to
int ledPin = 3;    // the pin the LED is connected to
int buttonState = 0;  // variable for reading the button state
int lastButtonState = 0; // variable for storing the last button state

void setup() {
  pinMode(buttonPin, INPUT);   // set the button pin as an input
  pinMode(ledPin, OUTPUT);    // set the LED pin as an output
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);  // read the current state of the button
  Serial.println(buttonState);
  if (buttonState != lastButtonState) {  // check if the button state has changed
    if (buttonState == HIGH) {  // if the button is pressed
      digitalWrite(ledPin, !digitalRead(ledPin)); // toggle the LED
      lastButtonState = buttonState;  // save the current button state for next time through the loop
    }
      delay(2000);
  }
  
  if (buttonState == lastButtonState) {  // check if the button state has changed
    if (buttonState == HIGH) {  // if the button is pressed
      digitalWrite(ledPin, !digitalRead(ledPin)); // toggle the LED
      lastButtonState = buttonState;  // save the current button state for next time through the loop
    }
      delay(2000);
  }
}