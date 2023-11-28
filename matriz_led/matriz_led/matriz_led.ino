// C++ code
#include <MD_MAX72xx.h> //biblioteca necessária para manipilar a matriz de led

#define DELAYTIME 150 //velocidade do texto
#define TIPO_HARDWARE MD_MAX72XX::GENERIC_HW //modelo da matriz de led
#define MAX_MODULOS 1 //qtd de matriz de led usadas
#define DATA_PIN 10 //pino DIN
#define CS_PIN 9  //pino CS
#define CLK_PIN 8 //pino CLK

MD_MAX72XX matriz(TIPO_HARDWARE, DATA_PIN, CLK_PIN, CS_PIN, MAX_MODULOS);

void setup(){
  matriz.begin();
  matriz.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY/2); //controla a intesidade
}

void loop(){
  escreve("FAIX U ELIIIIII");
  
  
}

void escreve(const char *p){
  byte charWidth;
  byte cBuf[8];
  matriz.clear(); //desliga os leds
  
  while(*p != '\0'){
    charWidth = matriz.getChar(*p++, sizeof(cBuf)/sizeof(cBuf[0]), cBuf);
    
    for(byte i = 0; i <= charWidth; i++){
      matriz.transform(MD_MAX72XX::TSL); //TSL = desloca um pixel a esquerda
      if(i < charWidth){
        matriz.setColumn(0, cBuf[i]);
        delay(DELAYTIME);
      }
   }
 }
}


