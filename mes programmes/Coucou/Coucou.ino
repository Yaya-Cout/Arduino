#include <Servo.h>

Servo myservo;
int Echo = A4;
int Trig = A5;
int ENA = 5;
int ENB = 11;
int ABS = 150;
int middleDistance = 0 ;

int trop_pres = 261.626;
int BUZZER = 10;
int TEMPO = 400;

void _mStop()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}
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
  myservo.attach(3);
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  _mStop();
}

void loop()
{
  myservo.write(90);
  delay(100);
  middleDistance = Distance_test();


  if (middleDistance <= 40)
  {
    _mStop();
    myservo.write(5);
    delay(500);

    myservo.write(90);
    delay(500);
    myservo.write(180);
    delay(500);

    //    delay(500);
    myservo.write(90);
    delay(500);

  }


  if (middleDistance <= 10)
  {

    while (trop_pres <= 1061.50)
    { trop_pres = trop_pres + 100;
      tone(BUZZER, trop_pres, TEMPO); delay(TEMPO);
    }
    if (trop_pres == 1061, 626 )
    {
      trop_pres = 261.626;
    }

  }
}
