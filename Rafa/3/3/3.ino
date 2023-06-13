#include <Servo.h>

#define POT_PORT A0

Servo s;

int pot;
int graus;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.attach(9);
  //s.write(0);
}

void loop() {

  if (Serial.available() > 0)
  {
    graus = Serial.parseInt();
    s.write(graus);
    delay(500);
  }
  /*pot = analogRead(POT_PORT);
  graus = map(pot, 0, 1023, 0, 180);

  Serial.println(graus);
  s.write(graus);
  delay(15);*/

  /*s.write(180);
  delay(500);

  s.write(0);
  delay(500);
  
  s.write(90);
  delay(1000);*/
}
