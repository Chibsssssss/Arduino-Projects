// Define traffic light pins for West/Intersection 1
const int red1Pin = 2;
const int yellow1Pin = 3;
const int green1Pin = 4;

// Define traffic light pins for North/Intersection 2
const int red2Pin = 5;
const int yellow2Pin = 6;
const int green2Pin = 7;

// Define traffic light pins for East/Intersection 3
const int red3Pin = 8;
const int yellow3Pin = 9;
const int green3Pin = 10;

// Define traffic light pins for South/Intersection 4
const int red4Pin = 11;
const int yellow4Pin = 12;
const int green4Pin = 13;

// Define the timings for each state in milliseconds
const unsigned long yellowDuration = 1000; // 2 seconds
const unsigned long greenDuration = 3000;  // 5 seconds

// Define pins for the Sensors
const int sensor1 = 1;
const int sensor2 = 0;
int sensor1WE;
int sensor2NS;

void setup() {
  // Set traffic light pins as OUTPUT
  pinMode(red1Pin, OUTPUT);
  pinMode(yellow1Pin, OUTPUT);
  pinMode(green1Pin, OUTPUT);
  pinMode(red2Pin, OUTPUT);
  pinMode(yellow2Pin, OUTPUT);
  pinMode(green2Pin, OUTPUT);
  pinMode(red3Pin, OUTPUT);
  pinMode(yellow3Pin, OUTPUT);
  pinMode(green3Pin, OUTPUT);
  pinMode(red4Pin, OUTPUT);
  pinMode(yellow4Pin, OUTPUT);
  pinMode(green4Pin, OUTPUT);
}

void loop() {

sensor1WE = digitalRead(sensor1);
sensor2NS = digitalRead(sensor2);

if (sensor1WE && sensor2NS)
{
//West
digitalWrite(yellow4Pin, HIGH);
digitalWrite(yellow1Pin, HIGH);
digitalWrite(red2Pin, HIGH);
digitalWrite(red3Pin, HIGH);

delay(yellowDuration);
digitalWrite(yellow4Pin, LOW);
digitalWrite(yellow1Pin, LOW);
digitalWrite(red1Pin, LOW);
digitalWrite(red4Pin, HIGH);

digitalWrite(green1Pin, HIGH);
delay(greenDuration);
digitalWrite(green1Pin, LOW);


//North

digitalWrite(red2Pin, LOW);
digitalWrite(yellow1Pin, HIGH);
digitalWrite(yellow2Pin, HIGH);
delay(yellowDuration);
digitalWrite(red1Pin, HIGH);
digitalWrite(yellow1Pin, LOW);
digitalWrite(yellow2Pin, LOW);

digitalWrite(green2Pin, HIGH);
delay(greenDuration);
digitalWrite(green2Pin, LOW);


//East

digitalWrite(red3Pin, LOW);
digitalWrite(yellow2Pin, HIGH);
digitalWrite(yellow3Pin, HIGH);
delay(yellowDuration);
digitalWrite(red2Pin, HIGH);
digitalWrite(yellow2Pin, LOW);
digitalWrite(yellow3Pin, LOW);

digitalWrite(green3Pin, HIGH);
delay(greenDuration);
digitalWrite(green3Pin, LOW);


//South

digitalWrite(red4Pin, LOW);
digitalWrite(yellow3Pin, HIGH);
digitalWrite(yellow4Pin, HIGH);
delay(yellowDuration);
digitalWrite(red3Pin, HIGH);
digitalWrite(yellow3Pin, LOW);
digitalWrite(yellow4Pin, LOW);

digitalWrite(green4Pin, HIGH);
delay(greenDuration);
digitalWrite(green4Pin, LOW);

for (int i = 0; i < 13; i++) {
    digitalWrite(i, LOW);
  }
} else if (sensor1WE && !sensor2NS)
{
  digitalWrite(green1Pin, HIGH);
  digitalWrite(red2Pin, HIGH);
  digitalWrite(green3Pin, HIGH);
  digitalWrite(red4Pin, HIGH);
  delay(5000);
  for (int i = 0; i < 13; i++) {
    digitalWrite(i, LOW);
  }

}else if (!sensor1WE && sensor2NS)
{
  digitalWrite(red1Pin, HIGH);
  digitalWrite(green2Pin, HIGH);
  digitalWrite(red3Pin, HIGH);
  digitalWrite(green4Pin, HIGH);
  delay(5000);
  for (int i = 0; i < 13; i++) {
    digitalWrite(i, LOW);
  }

}
}