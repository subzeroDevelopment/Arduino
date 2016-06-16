

void setup() {
Serial.begin(9600);  
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
}

void loop() {
  int x1=analogRead(A1);
  int y1=analogRead(A0);
  int x2=analogRead(A2);
  int y2=analogRead(A3);
Serial.println("Modulo del jostick");
Serial.print("x1:");
Serial.print(x1);
Serial.print("  y1:");
Serial.print(y1);
Serial.print("  x2:");
Serial.print(x2);
Serial.print("  y2:");
Serial.print(y2);

delay(100);
}
