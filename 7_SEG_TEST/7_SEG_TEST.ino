#define latchPin 5
#define dataPin 4
#define clockPin 6

byte seg0 = B00111111;
byte seg1 = B00000110;
byte seg2 = B01011011;
byte seg3 = B01001111;
byte seg4 = B01100110;
byte seg5 = B01101101;
byte seg6 = B01111101;
byte seg7 = B00000111;
byte seg8 = B01111111;
byte seg9 = B01101111;
byte fill = B10000000;
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg0);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg1);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg2);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg2);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg3);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg4);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg5);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg6);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg7);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg8);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, seg9);
  digitalWrite(latchPin, HIGH);
  delay(500);
  */
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, fill);
  digitalWrite(latchPin, HIGH);
  delay(500);
  fill = fill/128 + fill*2;
}
