const int sensorPin=8;
const int ledPin=13;
const int learnigPeriod=30*1000;
int learningCompleted=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  Serial.print("Empezando a leer entorno sin movimiento");
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()<learnigPeriod){
    delay(20);
    return;
  }
  if(learningCompleted==0){
    learningCompleted=1;
    Serial.println("Aprendizaje Completado");

  }
  if(digitalRead(sensorPin)==HIGH){
    Serial.println("movimiento detectado");
    digitalWrite(ledPin,HIGH);
  }
  else{
    Serial.println("No se detecta movimiento");
    digitalWrite(ledPin,LOW);
  }
  delay(100);
}

