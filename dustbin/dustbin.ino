#include <Servo.h>
int servorpin = 9;
Servo  Sev;
int trigpin = 12;
int echopin = 11;
int pingtraveltime;
int buzzerpin = 6;
void setup() {
  // put your setup code here, to run once:
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(servorpin, OUTPUT);
Sev.attach(servorpin);
Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delay(100);
  digitalWrite(trigpin, HIGH);
  delay(100);
  digitalWrite(trigpin, LOW);
  // put your main code here, to run repeatedly:
   pingtraveltime = pulseIn(echopin, HIGH);
Serial.println(pingtraveltime);
if(pingtraveltime < 2500){
  Sev.write(0);
}
else{
  Sev.write(180);
  }
}
