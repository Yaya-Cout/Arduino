#include <Yann.h>
int Trig = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(Trig));
}
