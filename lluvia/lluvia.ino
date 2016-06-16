int sensorMin=0;
int sensorMax=1024;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  int range = map(sensorReading,sensorMin,sensorMax,0,3);
  switch(range){
      case 0: 
        Serial.println("Mojadito");
        break;
      case 1:
        Serial.println("Lluviesita");
        break;
      case 2:
        Serial.println("Sin lluvia");
        break;  
    }
    delay(1);
}
