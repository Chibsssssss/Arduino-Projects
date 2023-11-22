#define ledPin 5
#define incPin 3
#define decPin 4

int ledValue = 0;
int inc;
int dec;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(incPin, INPUT_PULLUP);
  pinMode(decPin, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  inc = digitalRead(incPin);
  dec = digitalRead(decPin);
  if (inc == LOW) {
    ledValue = ledValue + 25;
    delay(500);
  }
  if (dec == LOW) {
    ledValue = ledValue - 25;
    delay(500);
  }
  if (ledValue > 255) {
    ledValue = 255;
  }
  if (ledValue < 0) {
    ledValue = 0;
  }
  analogWrite(ledPin, ledValue);
  Serial.println(ledValue);

}
