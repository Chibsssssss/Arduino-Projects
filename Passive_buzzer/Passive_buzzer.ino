#define buzzerPin 8
#define potPin A0
int potvalue;
int buzzdelay;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potvalue = analogRead(A0);
  buzzdelay = map(potvalue, 0, 1023, 0, 60 );

  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(buzzdelay);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(buzzdelay);

}
