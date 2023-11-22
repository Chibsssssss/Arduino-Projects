#define outLead 3

int outValue = 0;
int dt = 56;


void setup() {
  // put your setup code here, to run once:
  pinMode(outLead, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int j=0;j<=359;j++) {
    outValue = sin(j) * 255;
    analogWrite(outLead, 255);
    delayMicroseconds(outValue);
    analogWrite(outLead, 0);
    delayMicroseconds(outValue);
    Serial.println(outLead);
  }

}
