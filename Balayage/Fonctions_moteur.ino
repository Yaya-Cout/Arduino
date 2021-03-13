/*
  void Forward()
  {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(in1, HIGH); //digital output
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }
  void Back()
  {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }
  void left()
  {
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }
  void right()
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
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
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
    delay(10);
    Stop();
    temps_total = millis();

  }
*/
