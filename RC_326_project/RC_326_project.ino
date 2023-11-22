#include <IRremote.hpp>

void ON_all();
void OFF_all();
void BULB_1();
void BULB_2();
void BULB_3();
void BULB_4();

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

int bulb1 = 2;
int bulb2 = 4;
int bulb3 = 6;
int bulb4 = 8;
int ON_count = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;


void setup() {
  // put your setup code here, to run once:
  //pinMode(2,OUTPUT);
  pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
  pinMode(bulb3, OUTPUT);
  pinMode(bulb4, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn();
  //Serial.println("Enabled IRin");

}

void loop() {
  // put your main code here, to run repeatedly:
  //ON_all();
  if(irrecv.decode(&results)){
    //Serial.println(results.value);
    if(results.value == 1785214238){
      if (ON_count == 0) {
        ON_all();
        ON_count = 1;
      } else if (ON_count == 1) {
          OFF_all();
          ON_count = 0;
        }
      }
    else if(results.value == 1808161147){
      BULB_1();
      }
    else if(results.value == 1935374718){
      BULB_2();
      }
    else if(results.value == 516431295){
      BULB_3();
      }
    else if(results.value == 1158108118){
      BULB_4();
      }
    }
  irrecv.resume();

}


void ON_all() {
  // Turn on all bulbs
  digitalWrite(bulb1, HIGH);
  digitalWrite(bulb2, HIGH);
  digitalWrite(bulb3, HIGH);
  digitalWrite(bulb4, HIGH);
  count1 = count2 = count3 = count4 = 1;
}

void OFF_all() {
  // Turn off all bulbs
  digitalWrite(bulb1, LOW);
  digitalWrite(bulb2, LOW);
  digitalWrite(bulb3, LOW);
  digitalWrite(bulb4, LOW);
  count1 = count2 = count3 = count4 = 0;
}

void BULB_1() {
  if (count1 == 0){
    digitalWrite(bulb1, HIGH);
    count1 = 1;
    }
  else if (count1 == 1){
    digitalWrite(bulb1, LOW);
    count1 = 0;
   }
  }

void BULB_2(){
  if (count2 == 0){
    digitalWrite(bulb2, HIGH);
    count2 = 1;
    }
  else if (count2 == 1){
    digitalWrite(bulb2, LOW);
    count2 = 0;
   }
}

void BULB_3(){
  if (count3 == 0){
    digitalWrite(bulb3, HIGH);
    count3 = 1;
    }
  else if (count3 == 1){
    digitalWrite(bulb3, LOW);
    count3 = 0;
   }
}

void BULB_4(){
  if (count4 == 0){
    digitalWrite(bulb4, HIGH);
    count4 = 1;
    }
  else if (count4 == 1){
    digitalWrite(bulb4, LOW);
    count4 = 0;
   }
}
