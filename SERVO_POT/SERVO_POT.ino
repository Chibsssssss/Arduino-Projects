#include <Servo.h>
#define potPin A0
int servoPin = 9;
Servo servo;
int angle = 0;
int potValue;


void setup() {
    servo.attach(servoPin);
    pinMode(potPin, INPUT);
}

void loop() {

    // scan from 0 to 180 degrees
    /*for(angle = 0; angle < 180; angle++) {
        servo.write(angle);
        delay(15);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--) {
        servo.write(angle);
        delay(15);
    }
    */
    potValue = analogRead(potPin);
    angle = map(potValue, 0, 1023, 0, 180);

    servo.write(angle);  
   
}