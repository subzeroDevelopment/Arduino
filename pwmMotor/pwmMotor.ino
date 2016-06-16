void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tiempo=analogRead(0);
  Serial.print(tiempo);
  Serial.print("\t");
  Serial.print(tiempo/4);
  analogWrite(11,tiempo/4);
  Serial.print("\n");
  
}
