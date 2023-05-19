// C++ code
//
#include <Servo.h>
#define pino 7
//#define pot 0;
Servo servo;
int angulo = 0;

#define verde 11
#define vermelho 10

long read_ultrasonic_dist(int echo,int trigg){
  //echo:analogic
  //trigg:digital
  pinMode(trigg,OUTPUT);
  delayMicroseconds(2);

  digitalWrite(trigg,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg,LOW);
  pinMode(echo,INPUT);

  return 0.0173*pulseIn(echo,HIGH);

}

void setup()
{
 servo.attach(pino);
 Serial.begin(9600); 
}

void loop()
{
  /*while(Serial.available() == 0){
    //loop até algo ser inputado
  }*/
  //digitalWrite(vermelho,HIGH);
  //digitalWrite(verde,HIGH);
  String input = Serial.readString();
  
    long dist = read_ultrasonic_dist(A0,6);
    Serial.println(String(dist) + "cm");
    if(dist <= 10){
      servo.write(90);
      //led verde e apaga o vermelho
      digitalWrite(verde,HIGH);
      digitalWrite(vermelho,LOW);
      Serial.println(String(dist) + "cm");
    }
    else{
      //led vermelho e desliga verde
      digitalWrite(vermelho,HIGH);
      digitalWrite(verde,LOW);
      servo.write(0);
    }
  
}
