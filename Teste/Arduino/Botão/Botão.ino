#define vermelho 13
#define amarelo 12
#define botao 11

bool estado_amarelo= 0;
bool estado_vermelho= 1;
void setup()
{
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(botao)==LOW)
  {
    estado_vermelho = !estado_vermelho;
    digitalWrite(vermelho, estado_vermelho);
    estado_amarelo = !estado_amarelo;
    digitalWrite(amarelo, estado_amarelo);
  }
    while (digitalRead(botao)==LOW); 
    delay(100);
}