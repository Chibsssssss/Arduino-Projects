#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'*','0','#','/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

bool presentVal = false;
bool nextVal = false;
bool finalVal = false;

String num1, num2;
int answer = 0;
char operator;

void setup() {
  
  lcd.init();
  lcd.clear();
  lcd.backlit();



  Serial.begin(9600);
}

void loop() {
  
  if (key == )

}
