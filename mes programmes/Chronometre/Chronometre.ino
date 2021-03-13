unsigned long int boucle = 0;
unsigned long int jours = 0;
unsigned long int heures = 0;
unsigned long int minutes = 0;
unsigned long int secondes = 0;
unsigned long int milliemes = 0;
unsigned long int secondes_total = 0;

void setup() {
  Serial.begin(115200);
  //Serial.begin(9600);
}


void loop() {
  milliemes = millis();
  secondes_total = milliemes / 1000;
  secondes = milliemes / 1000; secondes = secondes % 60;
  minutes = milliemes / 60000; minutes = minutes % 60;
  heures = milliemes / 3600000; heures = heures % 24;
  jours = milliemes / 86400000;
  milliemes = milliemes - secondes_total * 1000;

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
