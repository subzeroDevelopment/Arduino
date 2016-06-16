const int analogPin=A0;
const int ledPin=13;

int sensorValue=0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(analogPin);
  if(sensorValue>500){
      digitalWrite(ledPin,HIGH);
    }
   else{
        digitalWrite(ledPin,LOW);    
    }

   Serial.print("sensor= ");
   Serial.println(sensorValue);
   delay(10);
}
