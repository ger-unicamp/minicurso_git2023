#include <Ultrasonic.h>

#define BUTTON 2
#define LED 10
#define TRIG 7
#define ECHO 8

bool esta_aceso = false;
bool padrao_led = false;

/*
  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal

  20K-ohm resistor is pulled to 5V. This configuration causes the input to read

  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
*/

int distancia;
Ultrasonic ultrasonic(TRIG, ECHO);

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  distancia = ultrasonic.distanceRead();  //método de leitura das distancias em CM
  Serial.println(distancia);
  if (distancia > 15) {
    esta_aceso = padrao_led;
  }
  else
  {
    esta_aceso = !padrao_led;
  }

  if (!digitalRead(BUTTON))
  {
    padrao_led = !padrao_led;
    delay(250);
  }

  digitalWrite(LED, esta_aceso);
  digitalWrite(LED_BUILTIN, !digitalRead(BUTTON));
  delay(100);
}

void liga_desliga()
{
  if (!digitalRead(BUTTON))
  {
    esta_aceso = !esta_aceso;
    digitalWrite(LED, esta_aceso);
    delay(500);
  }
}