/*
  Clignotement
  Allume la LED 13 (appelée LED_BUILTIN) pendant 1 seconde,
  puis l'éteint pendant 1 seconde.
*/


// le code dans cette fonction est exécuté une fois au début
void setup() {
  // indique que la broche de la LED une sortie :
  // on va modifier sa tension
  pinMode(LED_BUILTIN, OUTPUT);
}

// le code dans cette fonction est exécuté en boucle
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // allumer la LED (tension 5V sur la broche)
  delay(1000);                       // attendre 1000ms = 1s
  digitalWrite(LED_BUILTIN, LOW);    // éteindre la LED (tension 0V sur la broche)
  delay(1000);                       // attendre à nouveau 1 seconde
}
