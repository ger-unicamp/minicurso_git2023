// C++ code
//
#include <Servo.h>
Servo myservo; //cria um objeto baseado na biblioteca Servo

int angulo = 0; //variável para ler o valor do angulo
 
#define pinoServo 9


void setup()
{
  myservo.attach(pinoServo); //Diz que o objeto "myservo" está ligado ao pino 9
  Serial.begin(9600);
  
}

void loop()
{
  if (Serial.available() > 0) {
  angulo = Serial.parseInt(); //Lê o valor inteiro enviado pelo monitor serial
  myservo.write(angulo);      // Comando para mandar o servo para posição determinada pelo usuário
  delay(15);                  //Espera de 15ms para o servo se mover para a posição  desejada
  }  
}
