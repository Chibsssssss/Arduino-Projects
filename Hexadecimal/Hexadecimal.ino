byte myByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myByte += 1;
  Serial.println(myByte, DEC);
  delay(500);
}
