#define buttonPin 2
#define ledPin 5

int buttonState;
int lastbuttonState = 0;
int ledState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if ((buttonState==0) &&(lastbuttonState==0))
  {
    if (ledState == 0) {
      digitalWrite(ledPin, HIGH);
      ledState = 1;  
    } else {
      digitalWrite(ledPin, LOW);
      ledState = 0;
    }
  }
  lastbuttonState = buttonState;
  delay(500);
  Serial.println(ledState);
}
