#include <Stepper.h>
// change this to the number of steps on your motor
#define STEPS 48
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper1(STEPS,2,3,4,5);
Stepper stepper2(STEPS,8,9,10,11);
int steps = 0;
boolean can;
void setup(){
        // set the speed of the motor to 30 RPM
        stepper1.setSpeed(50);
        stepper2.setSpeed(50);
        Serial.begin(9600);
        can=true;
}

void loop() {
  if ( Serial.available()) {
      char ch = Serial.read();
      if(ch=='a') {
                stepper1.step(48);
                }
      if(ch=='b') {
                stepper1.step(-48);
                }          
  } 

}
