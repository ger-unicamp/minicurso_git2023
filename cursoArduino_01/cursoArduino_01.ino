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
  // distancia = ultrasonic.distanceRead();
  // Serial.println(distancia);
  // if (distancia <= 10) {
  //   digitalWrite(LED_R, LOW);
  //   digitalWrite(LED_G, HIGH);
  //   cancela.write(90);

  //   while (distancia <= 10)
  //   {
  //     distancia = ultrasonic.distanceRead();
  //     Serial.println(distancia);
  //     delay(200);
  //   }
  //   digitalWrite(LED_G, LOW);
  //   digitalWrite(LED_Y, HIGH);
  //   delay(1000);
  //   cancela.write(0);
  //   digitalWrite(LED_Y, LOW);
  //   digitalWrite(LED_R, HIGH);
  // }
  // delay(500);
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
