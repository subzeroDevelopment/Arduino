
void setup() {
  Serial.begin(9600);

}
void loop() {
  int sensor = analogRead(0);
  int rango=map(sensor,0,1023,0,3);

  switch(rango){
    case 0:
      Serial.println("diluvio");
      break;
    case 1:
      Serial.println("Alerta Lluvia");
    case 2:
      Serial.println("Sin Lluvia");
      break;
    }
    delay(1);
    

}

