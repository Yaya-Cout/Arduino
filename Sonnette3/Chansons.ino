int TEMPO = 400;

void hunger_games() {
  tone(BUZZER, SOL_5, 500); delay(500);
  tone(BUZZER, SI_B_5, 500); delay(500);
  tone(BUZZER, LA_5, 500); delay(500);
  tone(BUZZER, RE_5, 1000); delay(1100);

}

void theme_d_edwidge()
{
  tone(BUZZER, MI_3, 300); delay(250);
  tone(BUZZER, SOL_3, 100); delay(250);
  tone(BUZZER, FA_3, 200); delay(250);
  tone(BUZZER, MI_3, 300); delay(250);
  tone(BUZZER, SI_3, 200); delay(250);
  tone(BUZZER, LA_3, 400); delay(250);
  tone(BUZZER, FA_3, 400); delay(250);

  tone(BUZZER, FA_3, 300); delay(250);
  tone(BUZZER, SOL_3, 100); delay(250);
  tone(BUZZER, FA_3, 200); delay(250);
  tone(BUZZER, MI_3, 400); delay(250);
  tone(BUZZER, FA_3, 1000); delay(250);
  tone(BUZZER, MI_3, 800); delay(250);

  tone(BUZZER, MI_3, 300); delay(250);
  tone(BUZZER, SOL_3, 100); delay(250);
  tone(BUZZER, FA_3, 200); delay(250);
  tone(BUZZER, MI_3, 400); delay(250);
  tone(BUZZER, SI_3, 200); delay(250);
  tone(BUZZER, RE_4, 400); delay(250);
  tone(BUZZER, RE_4, 200); delay(250);
  tone(BUZZER, DO_4, 400); delay(250);
  tone(BUZZER, LA_3, 200); delay(250);
  tone(BUZZER, DO_4, 300); delay(250);
  tone(BUZZER, SI_3, 100); delay(250);
  tone(BUZZER, LA_3, 1000); delay(250);
  tone(BUZZER, SOL_3, 200); delay(250);
  tone(BUZZER, MI_3, 1300); delay(250);
  tone(BUZZER, SOL_3, 200); delay(250);
}


void toutes() {
  a = a - 1;
  Serial.println(a);
  tone(BUZZER, a, 1); delay(1);
  if (a = 0)
  {
    a = 2001;
  }
  
}
void ameliore() {
  int son_a_jouer = 483;
  int duree1 = 50;
  int duree2 = 5;
  while (son_a_jouer > 360)
  {
    if (son_a_jouer > 450)
      Serial.println("Si");
    tone(10, son_a_jouer, duree1); delay(duree1-2);
    son_a_jouer = son_a_jouer - 1;
    if (son_a_jouer == 470)
      son_a_jouer = 391;

    if ((son_a_jouer > 360) and (son_a_jouer < 392))
      Serial.println("Sol");
    tone(10, son_a_jouer, duree2); delay(duree2-2);
    //           tone(10, son_a_jouer, duree2); delay(duree2);
    son_a_jouer = son_a_jouer - 1;
  }
  Serial.println("Silence");
  tone(10, 0, 1000); delay(1000);
}
void Sonette() {
  Serial.println("Si");
  tone(10, SI_3, TEMPO); delay(TEMPO);
  Serial.println("Sol");
  tone(10, SOL_3, 600); delay(TEMPO);
  Serial.println("Silence");
  delay(1000);

}
