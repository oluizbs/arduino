#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor");
}

void loop() {
  Serial.print("Distancia em cm: ");
  Serial.println(ultrasonic.read());
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(ultrasonic.read(INC));
  delay(1000);

}
