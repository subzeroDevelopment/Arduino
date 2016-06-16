int outpin=13;
void setup() {
  pinMode(outpin,OUTPUT);

}
void loop() {
  digitalWrite(outpin,HIGH);
  delay(5000);
  digitalWrite(outpin,LOW);
  delay(5000);

}
