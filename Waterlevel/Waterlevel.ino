#define Lvl1 3
#define Lvl2 5
#define Lvl3 6
#define Lvl4 9
#define Sensor A0

void setup() {
  
  pinMode(Lvl1, OUTPUT);
  pinMode(Lvl2, OUTPUT);
  pinMode(Lvl3, OUTPUT);
  pinMode(Lvl4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int sense = analogRead(Sensor);
  int level = map(sense, 0, 800, 0, 1023);

  int reg1;
  int reg2;
  int reg3;
  int reg4;
  Serial.println(sense);
  if ((level >= 0) && (level <= 255))
  {
    reg1 = level;
    reg2 = 0;
    reg3 = 0;
    reg4 = 0;
  }else if ((level > 255) && (level <= 511))
  {
    reg1 = 255;
    reg2 = level - 255;
    reg3 = 0;
    reg4 = 0;
  }else if ((level > 511) && (level <= 767))
  {
    reg1 = 255;
    reg2 = 255;
    reg3 = level - 511;
    reg4 = 0;
  }else if (level > 767)
  {
    reg1 = 255;
    reg2 = 255;
    reg3 = 255;
    reg4 = level - 767;
  }
  analogWrite(Lvl1, reg1);
  analogWrite(Lvl2, reg2);
  analogWrite(Lvl3, reg3);
  analogWrite(Lvl4, reg4);

}
