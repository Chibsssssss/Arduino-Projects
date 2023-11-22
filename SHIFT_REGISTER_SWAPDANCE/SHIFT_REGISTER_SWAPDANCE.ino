#define latchPin 5
#define clockPin 6
#define dataPin 4

byte led1 = B01010101;
byte led2 = B10101010;


void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, led1);
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, led2);
  digitalWrite(latchPin, HIGH);
  delay(500);
}
