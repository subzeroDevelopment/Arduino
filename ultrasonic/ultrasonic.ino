int trigPin=8;
int echoPin=7;
float v=331.5+0.6*20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
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

void loop() {
  // put your main code here, to run repeatedly:
  int d=distanceM();
  Serial.println(d,DEC);
  delay(200);
}
