String msg1 = "Please enter the number ";
String msg2 = "Your number is: ";
int blinks;
int j;

void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(msg1);
  while (Serial.available() == 0)
  {

  }
  blinks = Serial.parseInt();
  for (j=1;j<=blinks;j=j+1) {
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
  }

}
