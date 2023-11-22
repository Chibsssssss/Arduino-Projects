#include <IRremote.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define BUTTON_1 0x6BC6597B 
#define BUTTON_2 0x735B797E  
#define BUTTON_3 0x1EC81DBF 
#define BUTTON_4 0x450753D6 
#define BUTTON_0 0xBA0F4EDF 
#define BUTTON_OK 0x4AC4DA9A 

int relay1 = 12;
int relay2 = 6;
int relay3 = 5;
int relay4 = 4;

int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;


void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == BUTTON_0)
    {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    }
    if (results.value == BUTTON_OK)
    {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH);
    }
    if (results.value == BUTTON_1)
    {
      if (state1 == 0)
      {
        digitalWrite(relay1, HIGH);
        state1 = 1;
        delay(500);
      }
      else if (state1 == 1)
      {
        digitalWrite(relay1, LOW);
        state1 = 0;
        delay(500);
      }
    }
    if (results.value == BUTTON_2)
    {
      if (state2 == 0)
      {
        digitalWrite(relay2, HIGH);
        state2 = 1;
        delay(500);
      }
      else if (state2 == 1)
      {
        digitalWrite(relay2, LOW);
        state2 = 0;
        delay(500);
      }
    }
    if (results.value == BUTTON_3)
    {
      if (state3 == 0)
      {
        digitalWrite(relay3, HIGH);
        state3 = 1;
        delay(500);
      }
      else if (state3 == 1)
      {
        digitalWrite(relay3, LOW);
        state3 = 0;
        delay(500);
      }
    }
    if (results.value == BUTTON_4)
    {
      if (state4 == 0)
      {
        digitalWrite(relay4, HIGH);
        state4 = 1;
        delay(500);
      }
      else if (state4 == 1)
      {
        digitalWrite(relay1, LOW);
        state4 = 0;
        delay(500);
      }
    }
    irrecv.resume();
  }
}
