#include <LiquidCrystal.h>
#define rs 13
#define e 12
#define d4 11
#define d5 10
#define d6 9
#define d7 8
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
#define pwmPin 6
#define currentPin A0
#define bVoltagePin A1
#define pvVoltagePin A2

double sensitivity = 0.66;
double adcValue = 0;
double offsetVoltage = 2.5;
double icVoltage = 0;
double icCurrent = 0;
double chargeCurrent;

double pvAVoltage;
double pvVoltageDiv;
double pvVoltage;

double bAVoltage;
double bVoltageDiv;
double bVoltage;

void setup() {
  lcd.begin(20, 4);
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
  pinMode(currentPin, INPUT);
  pinMode(bVoltagePin, INPUT);
  pinMode(pvVoltagePin, INPUT);

  lcd.setCursor(1, 2);
  lcd.print("PWM SOLAR CHARGER");
  delay(3000);
  lcd.clear();
  lcd.display();//Turning on the display again
}

void loop() {
  check();
  charge();
  disp();
}

void check() {
  pvAVoltage = analogRead(pvVoltagePin);
  pvVoltageDiv = ((pvAVoltage / 1024) * 5);
  pvVoltage = (pvVoltageDiv / 0.231);

  bAVoltage = analogRead(bVoltagePin);
  bVoltageDiv = ((bAVoltage / 1024) * 5);
  bVoltage = (bVoltageDiv / 0.231);

  adcValue = analogRead(currentPin);
  icVoltage = (adcValue / 1024.0) * 5; //Gets you V
  icCurrent = ((icVoltage - offsetVoltage) / sensitivity);
  chargeCurrent = icCurrent;

}

void charge() {
  if (bVoltage <= 11.8) {
    analogWrite(pwmPin, 10); //Fast Charge
  }

  if (bVoltage <= 12) {
    analogWrite(pwmPin, 127); //Steady charge
  }

  if (bVoltage > 12) {
    analogWrite(pwmPin, 248); //Trickle Charge
  }
}

void disp() {
  lcd.setCursor(1, 0);
  lcd.print("PV voltage: ");
  lcd.setCursor(13, 0);
  lcd.print(pvVoltage);
  lcd.setCursor(1, 1);
  lcd.print("Battery: ");
  lcd.setCursor(18, 1);
  lcd.print(bVoltage);
  lcd.setCursor(1, 2);
  lcd.print("Charge Current: ");
  lcd.setCursor(1, 2);
  lcd.print(chargeCurrent);

  delay(4000);
}
