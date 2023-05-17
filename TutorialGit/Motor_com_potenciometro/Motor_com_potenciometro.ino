#include <Servo.h>

Servo servo;

#define motor 9

int pot=0;
int val;

void setup() {
  // put your setup code here, to run once:
  servo.attach(motor);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(pot);
  val = map(val,0,1023,0,180);
  servo.write(val);
  Serial.println(val);

  delay(15);

}
