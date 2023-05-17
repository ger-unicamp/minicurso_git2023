
#define pinservo 9
#define pinpot 0
#include <Servo.h>
Servo myservo;
int ang = 0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(pinservo);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    ang = Serial.parseInt();
    myservo.write(ang);
    delay(15);
  }
}
