void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor=analogRead(0);
  int frecuencia=map(sensor,0,1023,100,880);
  Serial.print(frecuencia);
  Serial.print("\n");
  tone(9,frecuencia);
}
