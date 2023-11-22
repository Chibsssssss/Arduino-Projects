
double previous = 0, current = millis();
bool Motion; //Variable to store state of the pir sensor(motion sensor);
int Pir = 11, Led = 9, Ldr = A3 , Led2 = 10;  //Variable for where led, ldr and pir are connected to
int LdrRead; //Variable to store readings of the ldr(motion sensor);
void setup() {
  // put your setup code here, to run once:
 
  // Telling the System how each pin i'm using and how it would function
  pinMode(Pir, INPUT_PULLUP);
  pinMode(Ldr, INPUT);    
  pinMode(Led, OUTPUT);
  pinMode(Led2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Motion = digitalRead(Pir);
  LdrRead = analogRead(Ldr);
  
 
   Serial.println(Motion);
   Serial.println(LdrRead);

if(LdrRead <=1015){
  digitalWrite(Led, LOW);
  }
    else{
    digitalWrite(Led, HIGH);
    }
if(Motion == 0){
   digitalWrite(Led2, HIGH);
}
 if(millis() - previous > 60000){
      if(Motion == 1){
       digitalWrite(Led2, LOW);
      }
    previous = millis();  
   } 
} 
   
    
  
