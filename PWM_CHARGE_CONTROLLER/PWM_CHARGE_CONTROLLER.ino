#include <LiquidCrystal.h>
#define rs 13
#define e 12
#define d4 11
#define d5 10
#define d6 9
#define d7 8
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

#define pwmPin 3
#define currentSensorPin A0
#define batteryVoltagePin A1
#define pvVoltagePin A2

double offsetVoltage = 2.5;
double sensitivity = 0.066;
double adcValue = 0;
double icVoltage = 0;
double icCurrent = 0;
double chargeCurrent;

double pvVoltageValue;
double pvCurrentValue;
double pvPinVoltage;
double pvVoltage;
double pvCurrent;

double batteryVoltage;
double batteryVoltageValue;
double batteryPinVoltage;

String chargeState;

void setup() {
  
  lcd.begin(20, 4);
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
  pinMode(currentSensorPin, INPUT);
  pinMode(batteryVoltagePin, INPUT);
  pinMode(pvVoltagePin, INPUT);

  lcd.clear();
  lcd.display();
}

void loop() {
  state();
  charge();
  display();

}

void state() {
  pvVoltageValue = analogRead(pvVoltagePin);
  pvCurrentValue = analogRead(currentSensorPin);
  batteryVoltageValue = analogRead(batteryVoltagePin);

  pvPinVoltage = ((pvVoltageValue/1023)*5);
  pvVoltage =   map(pvPinVoltage, 0, 4.65, 0, 24);

  batteryPinVoltage = ((batteryVoltageValue/1023)*5);
  batteryVoltage = map(batteryPinVoltage, 0, 3.02, 10, 13);

  adcValue = analogRead(currentSensorPin);
  icVoltage = (adcValue / 1024.0) * 5;
  icCurrent = ((icVoltage - offsetVoltage) / sensitivity);
  chargeCurrent = icCurrent;
}

void charge() {
    if (batteryVoltage <= 10.5) {
    analogWrite(pwmPin, 10);
    chargeState = " Fast Charge";
  }

  if ((batteryVoltage > 10.5) && (batteryVoltage < 11.8)) {
    analogWrite(pwmPin, 127);
    chargeState = " Steady charge";
  }

  if (batteryVoltage > 12) {
    analogWrite(pwmPin, 248);
    chargeState = " Trickle Charge";
  }
}
void display() {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("PV Voltage: ");
  lcd.setCursor(13,0);
  lcd.print(pvVoltage);
  lcd.setCursor(17,0);
  lcd.print("V");

  lcd.setCursor(1,1);
  lcd.print("Battery: ");
  lcd.setCursor(10,1);
  lcd.print(batteryVoltage);
  lcd.setCursor(14,1);
  lcd.print("V");

  lcd.setCursor(1,2);
  lcd.print("PV Current: ");
  lcd.setCursor(13,2);
  lcd.print(chargeCurrent);
  lcd.setCursor(17,2);
  lcd.print("A");

  lcd.setCursor(3,3);
  lcd.print(chargeState);
  delay(3000);
}
