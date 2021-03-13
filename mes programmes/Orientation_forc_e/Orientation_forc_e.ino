#include <Servo.h>
int degres = 90;
Servo myservo;
void setup()
{
  myservo.attach(3);
  Serial.begin(9600);
}

void loop()
{
  myservo.write(degres);
  
}
