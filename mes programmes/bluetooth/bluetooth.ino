#include <Yann.h>

int TEMPO = 1;
int LED = 13;
int BUZZER = 12;
volatile int state = LOW;
String getstr;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 150;


void Blink()
{
  state = !state;
  digitalWrite(LED, state);
}
void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  Stop();
  Serial.println("Démarage");  
  tone(BUZZER, SOL_3, TEMPO * 2); delay(TEMPO * 2);
  Serial.println(" Fin du démarage");
}
void loop()

{

  getstr = Serial.readString();

  if (getstr != -1)
  {
    Serial.print(getstr);
    getstr.replace("\n", "");
    getstr.replace(" ", "");
    getstr.replace(",", "");
    getstr.replace("é", "e");
    getstr.replace("è", "e");
    getstr.replace("'", "");
    getstr.replace("_", "");
    getstr.toLowerCase();


    if ( getstr.equals("do3") )
    {
      tone(BUZZER, DO_3, 1000); delay(1000);
    }

    if (getstr.equals("re3"))
    {
      tone(BUZZER, RE_3, 1000); delay(1000);

    }


    if (getstr.equals("mi3"))
    {
      tone(BUZZER, MI_3, 1000); delay(1000);
    }

    if (getstr.equals("fa3"))
    {
      tone(BUZZER, FA_3, 1000); delay(1000);
    }

    if (getstr.equals("sol3"))
    {
      tone(BUZZER, SOL_3, 1000); delay(1000);
    }

    if (getstr.equals("la3"))
    {
      tone(BUZZER, LA_3, 1000); delay(1000);
    }

    if (getstr.equals("si3"))
    {
      tone(BUZZER, SI_3, 1000); delay(1000);
    }

    if (getstr.equals("do4"))
    {
      tone(BUZZER, DO_4, 1000); delay(1000);
    }

    if (getstr.equals("re4"))
    {
      tone(BUZZER, RE_4, 1000); delay(1000);
    }

    if (getstr.equals("mi4"))
    {
      tone(BUZZER, MI_4, 1000); delay(1000);
    }

    if (getstr.equals("fa4"))
    {
      tone(BUZZER, FA_4, 1000); delay(1000);
    }

    if (getstr.equals("sol4"))
    {
      tone(BUZZER, SOL_4, 1000); delay(1000);
    }

    if (getstr.equals("la4"))
    {
      tone(BUZZER, LA_4, 1000); delay(1000);
    }

    if (getstr.equals("si4"))
    {
      tone(BUZZER, SI_4, 1000); delay(1000);
    }

    if (getstr.equals("do5"))
    {
      tone(BUZZER, DO_5, 1000); delay(1000);
    }

    if (getstr.equals("aigue"))
    {
      tone(BUZZER, 4100, 1000); delay(1000);
    }

    if (getstr.equals("themededwidge"))
      {
             theme_d_edwidge();
      }


      if (getstr.equals("doremilaperdrix"))
      {
        do_re_mi_la_perdrix();
      }

      if (getstr.equals("santiano"))
      {
        santiano();
      }


      if (getstr.equals("touteslesnotes"))
      {
        toutes_les_notes();
      }

      if (getstr.equals("avancer"))
      {
        _mForward();
      }

      if (getstr.equals("reculer"))
      {
        _mBack();
      }

      if (getstr.equals("gauche"))
      {
        _mleft();
      }

      if (getstr.equals("droite"))
      {
        _mright();
      }



      if (getstr.equals("stop"))
      {
        _mStop();
      }


      if (getstr.equals("clignoter"))
      {
        Blink();
      }


    }
  }
