
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot=analogRead(0);
    Serial.print(pot);
    Serial.print("\n");
  digitalWrite(9,HIGH);
  delay(pot);
  digitalWrite(9,LOW);
  delay(1023-pot);


}
