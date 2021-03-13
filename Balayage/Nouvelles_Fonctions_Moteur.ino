void Forward() // Avancer
{
  analogWrite(ENA, VIT1);
  analogWrite(ENB, VIT2);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void Back() // Reculer
{
  analogWrite(ENA, VIT1);
  analogWrite(ENB, VIT2);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void left() // A Gauche
{
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right() // A Droite
{
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void Stop()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void tourner()
{
  temps_ecoule1 = millis() - temps_total;
  temps_ecoule2 = 0;
  while (temps_ecoule1 > temps_ecoule2) {
    Back();
    temps_ecoule2 = millis() - temps_ecoule1 - temps_total;
  }
  left();
  delay(20);
  Stop();
  temps_total = millis();

}
