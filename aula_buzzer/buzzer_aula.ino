// C++ code
float sinVal;
int toneVal;
int buzzer = 10;

void setup(){
  pinMode(buzzer, OUTPUT);

  
}

void loop(){
  for(int x=0; x<125; x++){
    sinVal = sin(x*(3.14/180));
    toneVal = 2000+(int(sinVal*1000));
    tone(buzzer, toneVal);
    delay(2);
  }
  noTone(buzzer);
}
