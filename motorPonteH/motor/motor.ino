class DCMotor {
  int spd = 255, pin1, pin2;
  
  public:
    void Pinout(int in1, int in2){
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
    }
    
    void Speed(int in1){
      spd = in1;
    }
    
    void Forward(){
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
    }
    
    void Backward(){
      analogWrite(pin2, spd);
      digitalWrite(pin1, LOW);
    }
    
    void Stop(){
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
  };

DCMotor Motor1, Motor2;
void setup() {
  Motor1.Pinout(4,5);
  Motor2.Pinout(9,10);
  
}

void loop() {
  Motor1.Speed(255);
  Motor2.Speed(255);
  Motor1.Forward();
  Motor2.Forward();

  delay(1000);
  Motor1.Backward();
  Motor2.Backward();

  delay(10000);
  Motor1.Stop();
  Motor2.Stop();

  delay(500);
}
