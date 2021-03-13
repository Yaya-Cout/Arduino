#define Bouton 13
#include <Notes et télécommandes.h>

void setup() {
  // put your setup code here, to run once:

  pinMode(Bouton,INPUT);
  Serial.begin(9600); // Pour afficher sur le moniteur série, écrire Serial.println(""); écrire le texte entre les gillemets.
  Serial.println("Démarage");

}

void Sonette() {
  // put your main code here, to run repeatedly:
  int BUZZER=10;
  Serial.println("Si");
  tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
  Serial.println("Sol");
  tone(BUZZER, SOL_3, 600); delay(TEMPO);
  Serial.println("Silence");
  tone(BUZZER, 0, TEMPO); delay(1000);

}
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Test");
  if(  digitalRead(Bouton) == HIGH){
      Serial.println("Début");
      Sonette();
  }

}
