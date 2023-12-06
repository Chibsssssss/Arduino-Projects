#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
int command;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Initializing...");
  Serial.println("The device has now started, you can now pair it with Bluetooth");
  pinMode(8, OUTPUT);


}

void loop() {

  if(Serial.available())
  {
    mySerial.write(Serial.read());
  }
  if(mySerial.available())
  {
    Serial.write(mySerial.read());
  }
  delay(20);

  command = mySerial.parseInt();


  if (command == 5)
  {
    if (buttonState==0)
    {
        digitalWrite(8, HIGH);
        buttonState = 1;
    } else 
    {
        digitalWrite(8, LOW);
        buttonState = 0;
    }

  }}
