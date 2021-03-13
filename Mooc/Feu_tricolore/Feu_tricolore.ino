/* 
  Vert : 4
  Orange : 3
  Rouge : 2
*/
int vert = 4;
int orange = 3;
int rouge = 2;
// le code dans cette fonction est exécuté une fois au début
void setup() {
  // indique que la broche de la LED une sortie :
  // on va modifier sa tension
  pinMode(vert, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(rouge, OUTPUT);
  Serial.begin(9600);
  Serial.println(micros());
  Serial.println(millis());
}

// le code dans cette fonction est exécuté en boucle
void loop() {
  digitalWrite(vert, HIGH);                 // allumer la LED (tension 5V sur la broche)
  delay(3000);                             // attendre 1000ms = 1s
  digitalWrite(vert, LOW);                // éteindre la LED (tension 0V sur la broche)
  digitalWrite(orange, HIGH);            // allumer la LED (tension 5V sur la broche)
  delay(1000);                          // attendre à nouveau 1 seconde
  digitalWrite(orange, LOW);           // éteindre la LED (tension 0V sur la broche)
  digitalWrite(rouge, HIGH);          // allumer la LED (tension 5V sur la broche)
  delay(3000);                       // attendre à nouveau 1 seconde
  digitalWrite(rouge, LOW);         // éteindre la LED (tension 0V sur la broche)
}