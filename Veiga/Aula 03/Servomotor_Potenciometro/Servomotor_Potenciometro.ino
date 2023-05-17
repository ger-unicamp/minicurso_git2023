// C++ code
//
#include <Servo.h>
Servo myservo; //cria um objeto baseado na biblioteca Servo

int potpin = 0; //Pino anaógico ligado ao potenciômetro

int val; //variável para ler o valor do potenciômetro
 
#define pinoServo 9


void setup()
{
  myservo.attach(pinoServo); //Diz que o objeto "myservo" está ligado ao pino 9
}

void loop()
{
  val = analogRead(potpin); // Le e armazena o do potenciometro
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);       // Comando para mandar o servo para posição "val" que foi mapeada
  delay(15);
    
}
