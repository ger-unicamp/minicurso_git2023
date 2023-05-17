#include <Servo.h>

Servo servo;

#define motor 9

int angulo=0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(motor);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available()>0)
  {
  angulo=Serial.parseInt();
  servo.write(angulo);
  
  delay(15);
  
  }

}
