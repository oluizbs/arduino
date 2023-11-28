#include<Servo.h>

const int pinoServo = 6;
Servo s;
int btnLeft = 12;
int btnRight = 11;

int pos;

void setup (){
  s.attach(pinoServo);
    s.write(0);
    pinMode(btnLeft, INPUT);
    pinMode(btnRight, INPUT);
}

void loop(){
  int stateLeft = digitalRead(btnLeft);
  int stateRight = digitalRead(btnRight);
  
  if(stateLeft == HIGH){
    for(pos = 0; pos <= 180; pos++){
      s.write(pos);
      delay(15);
    }
  }
  
  if(stateRight == HIGH){
    for(pos = 180; pos >= 0; pos--){
      s.write(pos);
      delay(15);
    }
   }
}
