#include <DHT.h>
#define DHTPIN 5//Seleccionamos el pin en el que se //conectará el sensor
#define DHTTYPE DHT11 //Se selecciona el DHT11 (hay //otros DHT)

const int pirpin=2;
const int learnigPeriod=30*1000;
int learningCompleted=0;

float h;
float t; 
float dis;

int trigPin=8;
int echoPin=7;
float v=331.5+0.6*20;

long start;

int puerta=0;
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que será usada por Arduino para comunicarse con el sensor

void setup() {
  Serial.begin(9600); //Se inicia la comunicación serial 
  pinMode(pirpin,INPUT);
  Serial.println("Iniciando entrenamiento....");
  dht.begin(); //Se inicia el sensor
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  for(int i = 0; i < 10; i++){
    delay(1000);
  }
  //attachInterrupt(0,movimiento,RISING);
 Serial.println("...Entrenamiento Terminado");
}

void loop() {
   long fin=millis();
  h = readHumedad(); //Se lee la humedad
  t = readTemp(); //Se lee la temperatura
  if(!isnan(h) || !isnan(t)){
    Serial.print("la temperatura es:");
    Serial.print(t);
    Serial.print("°C  ");
    Serial.print("humedad:");
    Serial.print(h);
    Serial.println("%");
  }
  delay(2000);
  dis=distanceM();
  Serial.print("Distancia:");
  Serial.println(dis);
  delay(2000);
  presencia();
  delay(500);
  if(estadoPuerta()){
     Serial.println("puerta cerrada");
    }
  else Serial.println("Puerta abierta");
  delay(500);
  Serial.println();
  
  
}

void movimiento(){
    Serial.println("Movimiento detectado");
    //detachInterrupt(0);
    start=millis();
  }


boolean estadoPuerta(){
    Serial.print("valor puerta:");
    Serial.println(analogRead(puerta));
     if(analogRead(puerta)>1000){
        return true;
      }
      return false;
  }

float readTemp(){
    return dht.readTemperature();
  }

float readHumedad(){
    return dht.readHumidity();
  }

float distanceM(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin,LOW);

  float tUs=pulseIn(echoPin,HIGH);
  float t=tUs/1000.0/1000.0/2;
  float d=t*v;
  return d*100;
  }

void presencia(){
    if(millis()<learnigPeriod){
    delay(20);
    return;
  }
  if(learningCompleted==0){
    learningCompleted=1;
    
  }
  if(digitalRead(pirpin)==HIGH){
    Serial.println("movimiento detectado");
  }
  else{
    Serial.println("No se detecta movimiento");
  }
  delay(100);
  }
