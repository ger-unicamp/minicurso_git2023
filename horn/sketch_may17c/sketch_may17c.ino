// C++ code
//
#include <Servo.h>
#define pino 9
//#define pot 0;
Servo servo;
int angulo = 0;

void setup()
{
 servo.attach(pino);
 Serial.begin(9600); 
}

void loop()
{
  if(Serial.available() > 0){
    angulo = Serial.parseInt();
    servo.write(angulo);
    delay(15);
  }
}
