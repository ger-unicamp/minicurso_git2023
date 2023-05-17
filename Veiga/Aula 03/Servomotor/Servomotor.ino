// C++ code
//
#include <Servo.h>
Servo myservo;
 
#define pinoServo 9


void setup()
{
  myservo.attach(pinoServo);
}

void loop()
{
  myservo.write(180); //mandar o servo para a posição 180
  delay(500);         //espera de 500ms
  myservo.write(0);   //mandar o servo para a posição 0
  delay(500);
  myservo.write(90);
  delay(500);
    
}
