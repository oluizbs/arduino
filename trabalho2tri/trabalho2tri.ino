#include<Servo.h>

int pinoSensor = 13;
int pinoMotor = 4;
int acionamento;
Servo s;

void setup() {
  pinMode(pinoSensor, INPUT);//define pino sensor como entrada
  s.attach(pinoMotor);
  s.write(0);
}

void loop() {
  acionamento = digitalRead(pinoSensor); //le o valor do sensor PIR
  int i = 180;
  
  if(acionamento == HIGH){
    if(i >= 180){
       for(i = 0; i < 180; i++){
        s.write(i);
        delay(10);
      }

   } else {
      for(i = 180; i > 0; i--){
        s.write(i);
        delay(10);
      }
      
    }
    
  }
}
