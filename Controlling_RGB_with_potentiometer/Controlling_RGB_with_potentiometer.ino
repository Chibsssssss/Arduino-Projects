#define RGB_RED_PIN 3
#define RGB_BLUE_PIN 6
#define RGB_GREEN_PIN 5
#define POTENTIOMETER_PIN A0

void digitalWriteRGB(byte red, byte blue, byte green)
{
  digitalWrite(RGB_RED_PIN, red);
  digitalWrite(RGB_BLUE_PIN, blue);
  digitalWrite(RGB_GREEN_PIN, green);
}

void setup()
{
  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
}

void loop()
{
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int mode = map(potentiometerValue, 0, 1023, 0, 6);
  
  switch (mode) {
    case 0:
      digitalWriteRGB(HIGH, LOW, LOW);
      break;
    case 1:
      digitalWriteRGB(LOW, HIGH, LOW);
      break;
    case 2:
      digitalWriteRGB(LOW, LOW, HIGH);
      break;
    case 3:
      digitalWriteRGB(HIGH, HIGH, LOW);
      break;
    case 4:
      digitalWriteRGB(HIGH, LOW, HIGH);
      break;
    case 5:
      digitalWriteRGB(LOW, HIGH, HIGH);
      break;
    case 6:
      digitalWriteRGB(HIGH, HIGH, HIGH);
      break;
    default:
      digitalWriteRGB(LOW, LOW, LOW);
      break;
  }
}