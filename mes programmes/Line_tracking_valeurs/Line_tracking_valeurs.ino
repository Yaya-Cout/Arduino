int num1, num2, num3;

void setup() {
  Serial.begin(9600);

}

void loop() {
  num1 = digitalRead(10);
  num2 = digitalRead(4);
  num3 = digitalRead(2);

  Serial.print("Num 1 = ");
  Serial.println(num1 );
  Serial.print("Num 2 = ");
  Serial.println(num2 );
  Serial.print("Num 3 = ");
  Serial.println(num3 );
  Serial.println("");
  delay(1000);
}
