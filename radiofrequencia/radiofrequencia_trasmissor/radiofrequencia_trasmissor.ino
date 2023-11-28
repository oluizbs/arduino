#include <RH_ASK.h>
#include <SPI.h> 
#include <DHT.h>
#include "DHT.h"

#define
const int pinoDHT11 = A4; //PINO ANALÓGICO UTILIZADO PELO DHT11

dht DHT; //VARIÁVEL DO TIPO DHT
RH_ASK driver; //CRIA O DRIVER PARA COMUNICAÇÃO

const int pinoBotao = 7; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON

String temp = "";

void setup(){
    Serial.begin(9600); //INICIALIZA A SERIAL
    driver.init(); //INICIALIZA A COMUNICAÇÃO RF DO DRIVER
    pinMode(pinoBotao, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
    //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
}
void loop(){

      DHT.read11(pinoDHT11); //LÊ AS INFORMAÇÕES DO SENSOR
      Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
      Serial.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
      Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
      Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
      Serial.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
      Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
      delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
   /* if(digitalRead(pinoBotao) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
        DHT.read11(pinoDHT); //LÊ AS INFORMAÇÕES DO SENSOR
        
        temp = "Umidade: ";
        
        driver.send((uint8_t *)temp, strlen(temp)); //ENVIA AS INFORMAÇÕES PARA O RECEPTOR
        driver.waitPacketSent(); //AGUARDA O ENVIO DAS INFORMAÇÕES
        delay(200); //INTERVALO DE 200 MILISSEGUNDOS */
    }
