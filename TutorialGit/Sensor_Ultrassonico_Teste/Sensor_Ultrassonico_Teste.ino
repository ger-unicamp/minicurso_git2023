#include <Ultrasonic.h>

#define echoPin A1
#define trigPin 11

Ultrasonic sensor(trigPin, echoPin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String input = "";
  int leitura = 0;


    leitura = sensor.Ranging(CM);
    Serial.println(String(leitura));

}
