int solaire = A5;
int pin = 12;
int temps1 = 0;
int temps2 = 0;
int soleil;
int state = 0;

void setup() {
  //  Serial.begin(115200);
  pinMode(solaire, INPUT);
  pinMode(pin, OUTPUT);

}

void loop() {
  temps1 = millis();
  temps1 = temps1 - temps2;
  soleil = analogRead(solaire);
  //  soleil = digitalRead(solaire);
  Serial.print("tone(10,"); Serial.print(soleil); Serial.println(",1);");
  //  tone(10,soleil,100);
  if (temps1 >= 1000) {
//    if (state == 0) {
//      state = 1;
//    }
//    else {
//      state = 0;
//    }
       Serial.print("                                                      ");
        Serial.println(state);
    pinMode(pin, state = ! state);
    state = state = ! state;
    temps2 = temps2 + 1000;
    delay(300);
  }

}
