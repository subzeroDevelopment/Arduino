/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo.write(30);
}

void loop() {
  if(Serial.available()){
      char chr=Serial.read();
      if(chr=='a'){
          myservo.write(30);
        }

      if(chr=='s'){
          myservo.write(50);
        }
        if(chr=='d'){
          myservo.write(70);
          
          }
              if(chr=='f'){
          myservo.write(90);
        }

      if(chr=='g'){
          myservo.write(110);
        }
        if(chr=='h'){
          myservo.write(130);
          
          }
    }
  
}

