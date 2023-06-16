#include <Servo.h>

Servo servo;

#define trigger 7
#define echo 8  // define cada porta no arduino como cada coisa
float tempoDoEcho = 0;
const float Velocidade_da_luz = 0.00034029; //metro por microsegundo m/us
float distancia = 0;
#define led_green 13
#define led_red 10


void setup() {
  pinMode(trigger,OUTPUT);// define o trigger como saida
  pinMode(echo,INPUT);

  pinMode(led_green,OUTPUT);
  pinMode(led_red,OUTPUT);
  
  digitalWrite (trigger, LOW);
  Serial.begin(9600);
  
  servo.attach(9);// liga o servo no pino 9

}

void funcao_gatilho_sensor() //fiz a funcao do gatilho, para o sensor ficar mandando pulsos, void é vazio logo n da return
{
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);  
}


float funcao_distancia (float tempoDoEcho)//funcao para calcular distancia, como n é void tem return
{
   float dist = (Velocidade_da_luz*tempoDoEcho)/2;
   return dist*100;
}


void loop() 

{
  funcao_gatilho_sensor();
  tempoDoEcho = pulseIn(echo,HIGH);
  distancia = funcao_distancia(tempoDoEcho);
  Serial.println(distancia);
  delay(200);

  if(distancia < 8)
  {
    servo.write (90);
    digitalWrite(led_green,HIGH);
    digitalWrite(led_red,LOW);
    delay(5000);
  }
  else
  {
    servo.write (0);
    digitalWrite(led_green,LOW);
    digitalWrite(led_red,HIGH);
  }
}
