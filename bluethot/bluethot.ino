#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

int a=0;
char c;
char d;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Goodnight mon");

  mySerial.begin(9600);
  mySerial.println("Hello world");

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  if(Serial.available()){
    c=Serial.read();
    delay(10);
  
     mySerial.write(c);
    
    }
    delay(10);
    if(mySerial.available()){
        d=mySerial.read();
        delay(10);

        Serial.write(d);
      }

}
