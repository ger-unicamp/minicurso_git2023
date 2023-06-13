#define LED_RED 7
#define LED_YELLOW 8

void setup()
{
  pinMode(LED_RED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hehe");
}

void loop()
{
  Red(HIGH);
  Yellow(LOW);
  delay(1000);
  Red(LOW);
  Yellow(HIGH);
  delay(1000);
}

void Red(bool b)
{
  digitalWrite(LED_RED, b);
}

void Yellow(bool b)
{
  digitalWrite(LED_YELLOW, b);
}