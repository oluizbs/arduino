// C++ code
//
int pinoledverm = 5;
int pinoledazul = 6;
int pinopir = 3;
int acionamento;

void setup()
{
  pinMode(pinoledverm, OUTPUT);//Define pino como saida
  pinMode(pinoledazul, OUTPUT);//Define pino como saida
  pinMode(pinopir, INPUT);//Define pino sensor como entrada
  Serial.begin(9600);
}

void loop()
{
  acionamento = digitalRead(pinopir); //le o valor do sensor PIR
  Serial.println(acionamento);
  if(acionamento == LOW){
    digitalWrite(pinoledverm, LOW);
    digitalWrite(pinoledazul, HIGH);
  }
  else {
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledazul, LOW);
  }
  
}
