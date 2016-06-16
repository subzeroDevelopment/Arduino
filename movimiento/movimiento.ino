int sensorPin=8;
int ledPin=13;
int learningPeriod=30*1000;
int learningCompleted=0;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  Serial.println("Sensor de movimiento");
  pinMode(ledPin,OUTPUT);  
}

void loop() {
  if(millis() < learningPeriod){
     delay(20);
     return;
    }
    if(learningCompleted==0){
             learningCompleted=1;
             Serial.println("Learning completed.");
      }
      if(digitalRead(sensorPin)==HIGH){
         Serial.println("Movimiento detectado");
         digitalWrite(ledPin,HIGH);
        }else{
            Serial.println("No movimiento detectado");
            digitalWrite(ledPin,LOW);
          }
          delay(100);

}
