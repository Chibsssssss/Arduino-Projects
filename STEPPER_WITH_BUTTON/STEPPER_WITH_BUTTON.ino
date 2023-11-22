#include <Stepper.h>
#define buttonPin 3

int stepsPerRevolution = 2038;
int motorDir = 1;

int motorSpeed = 5;
int dt = 500;
int buttonValNew;
int buttonValOld = 1;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);

}

void loop() {
  // put your main code here, to run repeatedly
  
  buttonValNew = digitalRead(buttonPin);

  if (buttonValOld==1 && buttonValNew==0){
    motorDir = motorDir* (-1);
  }
  myStepper.step(motorDir*1);
  buttonValOld = buttonValNew;
  Serial.println(buttonValNew);
  
}
