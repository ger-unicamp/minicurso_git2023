#define LED_G 7
#define LED_R 6
#define LED_Y 5
#define TRIG 9
#define ECHO 8
#define SERVO 10

#include <Servo.h>
#include <Ultrasonic.h>

int distancia;
Ultrasonic ultrasonic(TRIG, ECHO);
Servo cancela;

void setup() {
  Serial.begin(9600);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  cancela.attach(SERVO);
  cancela.write(0);
  digitalWrite(LED_R, HIGH);
}

void loop() {
  distancia = getDistancia();
  if (distancia <= 15) {
    abrirCancela();
    apagarLed(LED_G);
    acenderLed(LED_Y);
    delay(1000);
    fecharCancela();
  }
  delay(500);
}

int getDistancia()
{
  int distancia = ultrasonic.distanceRead();
  Serial.println(distancia);
  return distancia;
}

void abrirCancela() {
  apagarLed(LED_R);
  acenderLed(LED_G);
  cancela.write(90);
  Serial.println("Abriu");
  while(distancia <= 15) {
    distancia = getDistancia();
    delay(200);
  }
}

void fecharCancela() {
  apagarLed(LED_Y);
  acenderLed(LED_R);
  Serial.println("Fechou");
  cancela.write(0);
}

void acenderLed(int led) {
  digitalWrite(led, HIGH);
}

void apagarLed(int led) {
  digitalWrite(led, LOW);
}
