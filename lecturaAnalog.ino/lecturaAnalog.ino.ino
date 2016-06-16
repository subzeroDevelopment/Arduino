int pin=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensor=analogRead(0);
  float voltaje=sensor*5/1024;
  Serial.print(sensor);
  Serial.print("\t");
  Serial.print(voltaje);
   Serial.print("\t");
  float lumi=map(sensor,0,1024,0,5);
   Serial.print("\t");
  Serial.print(lumi);
  Serial.print("\n");
  delay(1000);
}
