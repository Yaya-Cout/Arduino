#define Bouton 4
#define BUZZER 10
//#define Boutontoutes 8
//#define Boutonameliore 4
#define Tempo 500
#include <Yann.h>
int a = 2001;
int test = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Bouton, INPUT);
  Serial.begin(115200); // Pour afficher sur le moniteur série, écrire Serial.println(""); écrire le texte entre les gillemets.
  Serial.println("Démarage");

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Test");
  if (  digitalRead(Bouton) == HIGH) {
    // Serial.println("Début");
    // hunger_games();
    // Sonette();
    // ameliore();
    toutes();
  }
}
