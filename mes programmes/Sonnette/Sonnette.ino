void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  #include <Notes et télécommandes.h>
  int BUZZER=10;
  Serial.println("Si");
  tone(10, SI_3, TEMPO); delay(TEMPO);
  Serial.println("Sol");
  tone(10, SOL_3, 600); delay(TEMPO);
  Serial.println("Silence");
  tone(10, 0, TEMPO); delay(1000);

}
