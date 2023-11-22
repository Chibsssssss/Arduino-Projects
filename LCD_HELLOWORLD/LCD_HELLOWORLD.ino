#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(2,0);
  lcd.print("Hello World");
  lcd.setCursor(1,1);
  lcd.print("CHIBS IS");
}

void loop() {
  // put your main code here, to run repeatedly:

}
