#include <Yann.h>
int state = 0;
int LED = 13;

void Blink()
{
  state = !state;
  digitalWrite(LED, state);
}
void setup()
{
  Serial.begin(9600);
  Serial.println("Démarage");


}

void loop() {
  int BUZZER = 12;
  while (true) {
    int num1, num2, num3;
    num1 = digitalRead(10);
    num2 = digitalRead(4);
    num3 = digitalRead(2);


    if ((num1 == 0))
    { tone(BUZZER, DO_4, 100); delay(100);
      Serial.println("Droite");
      num2 = digitalRead(2);
      Blink();
      continue;
    }



    if ((num3 == 0))
    { tone(BUZZER, DO_3, 100); delay(100);
      Serial.println("Gauche");
      num2 = digitalRead(2);
      Blink();
      continue;
    }

    if ((num2 == 0))
    { tone(BUZZER, FA_3, 100); delay(100);
      Serial.println("Devant");
      Blink();
      num2 = digitalRead(2);
      continue;
    }
  }
}
