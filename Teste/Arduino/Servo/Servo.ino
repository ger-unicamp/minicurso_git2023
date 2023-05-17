#include <Servo.h>
#define servo 13
Servo Myservo;
int angulo = 0;

void setup() {
Myservo.attach(servo);
Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    angulo=Serial.parseInt();
    Myservo.write(angulo);
    delay(15);
    }
}
