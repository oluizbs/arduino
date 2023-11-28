#include <IRremote.h> 

int pinoLedVerde = 3;
int pinoLedVermelho = 8;
int pinoLedAzul = 9;
int portaFotorreceptor = 2;

int stVerde = 0;
int stVermelho = 0;
int stAzul = 0;

IRrecv irrecv(portaFotorreceptor);
decode_results results;

void setup() {
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLedAzul, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();    
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.print("Codigo HEX: ");
    Serial.println(results.value, HEX);
    Serial.print("Codigo DEC: ");
    Serial.println(results.value);
    Serial.println("");
    irrecv.resume();
    if(results.value == 1086259455){
      if(stVermelho == 1){
        digitalWrite(pinoLedVermelho, LOW);
        stVermelho = 0;
      }
      else {
        digitalWrite(pinoLedVermelho,HIGH);
        stVermelho = 1;
      }
    }
    if(results.value == 1086292095){
      if(stVerde == 1){
        digitalWrite(pinoLedVerde, LOW);
        stVerde = 0;
      }
      else{
        digitalWrite(pinoLedVerde,HIGH);
        stVerde = 1;
      }
    }
    if(results.value == 1086275775){
      if(stAzul == 1){
        digitalWrite(pinoLedAzul, LOW);
        stAzul = 0;
      }
      else{
        digitalWrite(pinoLedAzul,HIGH);
        stAzul = 1;
      }
     }
    }
  delay(100);
}
