/*
  unsigned long int boucle = 0;
  unsigned long int jours = 0;
  unsigned long int heures = 0;
  unsigned long int minutes = 0;
  unsigned long int secondes = 0;
  unsigned long int milliemes = 0;

  void setup() {
  //Serial.begin(115200);
  Serial.begin(9600);
  }


  void loop() {
  milliemes = millis();
  secondes = milliemes / 1000;
  minutes = milliemes / 60000;
  heures = milliemes / 3600000;
  jours = milliemes / 86400000;
  milliemes = milliemes - secondes * 1000;

  if (jours > 0 ) {
    Serial.print(jours);
    Serial.print(":");
  }

  if (heures > 0 ) {
    Serial.print(heures);
    Serial.print(":");
  }

  if (minutes > 0 ) {
    Serial.print(minutes);
    Serial.print(":");
  }

  if (secondes > 59) {
    secondes = secondes - 60
               ;
  }

  if (secondes < 10) {
    Serial.print("0");
    Serial.print(secondes);
    Serial.print(":");
  }

  if (secondes > 9 ) {
    Serial.print(secondes);
    Serial.print(":");
  }




  Serial.println(milliemes);
  }
*/
