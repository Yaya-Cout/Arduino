//#include <Notes et télécommandes.h>
int Echo = A4;
int Trig = A5;
int middleDistance = 0 ;
int BUZZER = 10;
int TEMPO = 1;

int Distance_test()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance / 58;
  return (int)Fdistance;
}

void setup()
{
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
}

void loop()
{
  unsigned long frequence;
  while (true) {
    //delay(100);
    middleDistance = Distance_test();
    frequence = (unsigned long)(middleDistance) * 7970 / 130 + 30;
//    Serial.print(middleDistance);  Serial.print("  "); Serial.println(frequence); if (middleDistance < 10)
    if (middleDistance < 150)
    {
      tone(BUZZER, frequence, TEMPO);

    }


  }
}
