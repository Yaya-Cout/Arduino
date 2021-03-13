int temps_total = 0;
int temps_ecoule1 = 0;
int temps_ecoule2 = 0;
int temps_ecoule3 = 0;
int Echo = A4;
int Trig = A5;
int Distance = 0 ;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 150;
int num1, num2, num3;
int VIT = 150;
int VIT1 = VIT;
int VIT2 = VIT;

int Distance_test()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance / 58;
  return (int)Fdistance;
}

void setup() {
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  Serial.begin(9600);
  millis();

}

void loop() {
  num1 = digitalRead(10);
  num2 = digitalRead(4);
  num3 = digitalRead(2);
  int Distance = Distance_test();
  if (Distance < 20)
  {
    tourner();
  }

  if ((num1 == 1)) {
    //   Back();
    //    delay(1000);
    //    left();
    //   delay(20);
    //  Forward();
    //   temps_total = temps_total + 2000;

    Stop();
  }



  if ((num3 == 1)) {
    // Back();
    // delay(1000);
    //  left();
    //   delay(20);
    //  Forward();
    //   temps_total = temps_total + 2000;
    Stop();
  }

  if ((num2 == 1)) {
    // Back();
    // delay(1000);
    // left();
    // delay(20);
    // Forward();
    // temps_total = temps_total + 2000;
    Stop();
  }

  else {
    Forward();
  }
}
