/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for(pos=0;pos<100;pos+=1){
      myservo.write(pos);
      delay(15);
    }
   for(pos=100;pos>=1;pos-=1){
      myservo.write(pos);
      delay(15);
    }
}

