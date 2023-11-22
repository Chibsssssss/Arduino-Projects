#define photoPin A0
int lightValue;

void setup() {
  pinMode(photoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  lightValue = analogRead(photoPin);
  Serial.println(lightValue);
  delay(500);

}
