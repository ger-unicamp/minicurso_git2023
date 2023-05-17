#include <Servo.h>
#define pinServo 10
int pot = 0;
int valorpot; 
int angulo = 0;
Servo (severo);

void setup() {
  
severo.attach(pinServo);
Serial.begin(9600);
}

void loop() {

  if(Serial.available()>0){
    angulo = Serial.parseInt();
    severo.write(angulo);
    delay(1000);
  }
}
