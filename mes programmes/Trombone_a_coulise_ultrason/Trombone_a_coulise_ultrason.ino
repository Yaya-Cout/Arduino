int Echo = A4;
int Trig = A5;
int middleDistance = 0 ;
int BUZZER = 10;
int TEMPO = 300;

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
#include <Notes et télécommandes.h>
  while (true) {
    middleDistance = Distance_test();
    Serial.println(middleDistance);
    if (middleDistance < 10)
    {
      tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
      continue;

    }

    if (middleDistance < 12)
    {
      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 14)
    {
      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 16)
    {
      tone(BUZZER, FA_3, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 18)
    {
      tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 20)
    {
      tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
      continue;
    }


    if (middleDistance < 22)
    {
      tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
      continue;
    }


    if (middleDistance < 24)
    {
      tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 26)
    {
      tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 28)
    {
      tone(BUZZER, MI_4, TEMPO); delay(TEMPO);
      continue;
    }
    if (middleDistance < 30)
    {
      tone(BUZZER, FA_4, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 32)
    {
      tone(BUZZER, SOL_4, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 34)
    {
      tone(BUZZER, LA_4, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 36)
    {
      tone(BUZZER, SI_4, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 38)
    {
      tone(BUZZER, DO_5, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 40)
    {
      tone(BUZZER, RE_5, TEMPO); delay(TEMPO);
      continue;
    }


    if (middleDistance < 42)
    {
      tone(BUZZER, MI_5, TEMPO); delay(TEMPO);
      continue;
    }
    if (middleDistance < 44)
    {
      tone(BUZZER, FA_5, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 46)
    {
      tone(BUZZER, SOL_5, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 48)
    {
      tone(BUZZER, LA_5, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 50)
    {
      tone(BUZZER, SI_5, TEMPO); delay(TEMPO);
      continue;
    }


    if (middleDistance < 52)
    {
      tone(BUZZER, DO_6, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 54)
    {
      tone(BUZZER, RE_6, TEMPO); delay(TEMPO);
      continue;
    }


    if (middleDistance < 56)
    {
      tone(BUZZER, MI_6, TEMPO); delay(TEMPO);
      continue;
    }
    if (middleDistance < 58)
    {
      tone(BUZZER, FA_6, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 60)
    {
      tone(BUZZER, SOL_6, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 62)
    {
      tone(BUZZER, LA_6, TEMPO); delay(TEMPO);
      continue;
    }
    if (middleDistance < 64)
    {
      tone(BUZZER, SI_6, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 66)
    {
      tone(BUZZER, DO_7, TEMPO); delay(TEMPO);
      continue;
    }

    if (middleDistance < 68)
    {
      tone(BUZZER, RE_7, TEMPO); delay(TEMPO);
      continue;
    }


    if (middleDistance < 70)
    {
      tone(BUZZER, MI_7, TEMPO); delay(TEMPO);
      continue;
    }
    if (middleDistance < 72)
    {
      tone(BUZZER, FA_7, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 74)
    {
      tone(BUZZER, SOL_7, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 76)
    {
      tone(BUZZER, LA_7, TEMPO); delay(TEMPO);
      continue;

    }
    if (middleDistance < 78)
    {
      tone(BUZZER, SI_7, TEMPO); delay(TEMPO);
      continue;
    }

  }
}
