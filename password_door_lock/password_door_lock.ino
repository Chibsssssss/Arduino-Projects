#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ ROWS ][ COLS ] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ ROWS ] = {0, 1, 2, 3};
byte colPins[ COLS ] = {4, 5, 6};

Keypad customKeypad = Keypad ( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
const int Motor = 7;
char keycount = 0;
char code [5];
char passCode[5] = "1346";

void setup() {
  // put your setup code here, to run once:
  pinMode(Motor, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Input Passkey:");
  lcd.setCursor(0, 1);
  lcd.cursor();
  digitalWrite(Motor, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  if (customKey && (keycount < 4) && (customKey != '*') && (customKey != '#')) {
    lcd.print("*");
    code[keycount] = customKey;
    keycount++;
  }
  code[4] = '\0';
  if (customKey == '*')
  {
    Lock();
  }
  if (customKey == '#')
  {
    if (strcmp(code, passCode) == 0)
    {
      refresh();
      lcd.print("Access Granted!");
      digitalWrite(Motor, HIGH);
      delay(3000);
      Lock();
    }
    else
    {
      refresh();
      lcd.print("Access Denied!");
      delay(500);
      Lock();
    }
  }
}

void Lock ()
{
  digitalWrite(Motor, LOW);
  refresh();
  lcd.print("Door Locked");
  delay(1500);
  refresh();
  keycount = 0;
}


void refresh ()
{
  lcd.clear();
  lcd.print("Input Passkey:");
  lcd.setCursor(0, 1);
}
