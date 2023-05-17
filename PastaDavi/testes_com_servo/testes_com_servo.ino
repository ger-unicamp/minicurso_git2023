#include <Servo.h>
#define servomotor 9
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(servomotor);
  Serial.begin(9600);
  
}
int angulo=0;

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
 angulo = Serial.parseInt(); //pega somente valores inteiros
 myservo.write(angulo);
 delay(15);
 Serial.print("O último valor lido foi de: ");
 Serial.println(angulo);
}
