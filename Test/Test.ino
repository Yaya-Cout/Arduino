#define LED_PIN 13
String getstr;
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Démarrage");
}

void loop()
{
    // Serial.println(micros());
    // Serial.println(millis());

    // while(Serial.available()) {
    //      int lu = Serial.read();
    //     flash(lu);
    // }
    // delay(10);
    getstr = Serial.readString();

      if (getstr != -1 || getstr != "") 
      {
        Serial.print(getstr);
        int taille = getstr.length();
        flash(taille);
        getstr.replace("\n", "");
        getstr.replace(" ", "");
        getstr.replace(",", "");
        getstr.replace("é", "e");
        getstr.replace("è", "e");
        getstr.replace("'", "");
        getstr.replace("_", "");
        getstr.toLowerCase();
  }
}

void flash(int n)
{
  for (int i = 1; i < n; i++)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
} 