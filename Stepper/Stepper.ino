#include <Stepper.h>

const int stepsPerRevolution = 48;

Stepper myStepper(stepsPerRevolution, 8,9,10,11);

void setup() {

// set the speed at 60 rpm: myStepper.setSpeed(60);
 myStepper.setSpeed(60);

// initialize the serial port: Serial.begin(9600);
Serial.begin(9600);

}

void loop() {

// step one revolution in one direction:

Serial.println("clockwise");

myStepper.step(stepsPerRevolution);

delay(500);

// step one revolution in the other direction:

Serial.println("counterclockwise");

myStepper.step(-stepsPerRevolution);

delay(500);

}
