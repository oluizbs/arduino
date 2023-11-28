#define NOTE_DO  264
#define NOTE_RE  297
#define NOTE_MI  330
#define NOTE_FA  352

#define buzzer 12

int iniciar = 13;
int botao_atv = 0;
int jogada = 0;

int tons[4] = { NOTE_FA, NOTE_MI, NOTE_RE, NOTE_DO };
int ordem[12] = {};
int leds[4] = { 2, 3, 4, 5 };
int botoes[4] = { 8, 9, 10, 11 };

bool perdeu = false;
bool start = false;
 
void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
  for (int i = 0; i <= 3; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
  }
  pinMode(buzzer, OUTPUT);
  pinMode(iniciar, INPUT_PULLUP);
  randomSeed(analogRead(0));
}
 
void loop() {
  while (!start) {
    if (!digitalRead(iniciar) == HIGH) {
      start = true;
      break;
    }
  }
  if (start && perdeu) {
    for (int i = 0; i <= 3; i++) {
      digitalWrite(leds[i], LOW);
    }
    start = false;
    perdeu = false;
    jogada = 0;
  }
  if (jogada == 0 && start) {
    tocarSomDeInicio();
    delay(500);
  }
  if (start && !perdeu) {
    proximaRodada();
    reproduzirOrdem();
    aguardarJogador();
    delay(1000);
  }
}
void proximaRodada() {
  int numero_sorteado = random(0, 4);
  ordem[jogada++] = numero_sorteado;
}
void reproduzirOrdem() {
  for (int i = 0; i < jogada; i++) {
    tone(buzzer, tons[ordem[i]]);
    digitalWrite(leds[ordem[i]], HIGH);
    delay(300);
    noTone(buzzer);
    digitalWrite(leds[ordem[i]], LOW);
    delay(100);
  }
  noTone(buzzer);
}
void aguardarJogador() {
  for (int i = 0; i < jogada; i++) {
    aguardarJogada();
    if (ordem[i] != botao_atv) {
      gameOver();
    } 
    
    if (perdeu) {
      break;
    }
  }
}
 
void aguardarJogada() {
  bool jogada_efetuada = false;
  
  while (!jogada_efetuada) {
    for (int i = 0; i <= 3; i++) {
      if (!digitalRead(botoes[i])) {
        botao_atv = i;
        tone(buzzer, tons[i]);
        digitalWrite(leds[i], HIGH);
        delay(200);
        digitalWrite(leds[i], LOW);
        noTone(buzzer);
        jogada_efetuada = true;
      }
    }
    delay(10);
  }
}

void gameOver() {
  for (int i = 0; i <= 3; i++) {
    tone(buzzer, tons[i]);
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    noTone(buzzer);
  }
  tone(buzzer, tons[3]);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    delay(200);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[2], LOW);
    digitalWrite(leds[3], LOW);
    delay(200);
  }
  noTone(buzzer);
  delay(1000);
  perdeu = true;
}
 
void tocarSomDeInicio() {
  tone(buzzer, tons[3]);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
  }
  noTone(buzzer);
}
