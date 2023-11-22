#include <LiquidCrystal_I2C.h>
int buttonPin=A0;
int buttonVal;

int numMeas=100;
float avMeas;
int j;
float bucket=0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin=2;
int echoPin=3;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;
int dt=5000;

void setup() {

lcd.init();
lcd.clear();
lcd.backlight();

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH);
Serial.begin(9600);

}

void loop() {

lcd.setCursor(0,0);
lcd.print("Place the Target");
lcd.setCursor(0,1);
lcd.print("Press to Measure");
buttonVal=digitalRead(buttonPin);
while (buttonVal==1){
  buttonVal=digitalRead(buttonPin);
}
lcd.setCursor(0,0);
lcd.clear();
lcd.print("Measuring . . .");
for (j=1;j<=numMeas;j=j+1){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTravelTime=pulseIn(echoPin,HIGH);
  delay(25);
  pingTravelDistance=(pingTravelTime*0.034/2);
  distanceToTarget=pingTravelDistance;
  bucket=bucket+distanceToTarget;
}
avMeas=bucket/numMeas;
Serial.print("Av. Dist. to Target is: ");
Serial.print(avMeas);
Serial.println(" m");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Target Distance");
lcd.setCursor(0,1);
lcd.print(distanceToTarget);
lcd.print(" m");
delay(dt);
}