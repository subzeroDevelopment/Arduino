#include <AFMotor.h>
#include <Servo.h>

#define MAX_SPEED 180
#define MAX_SPEED_OFFSET 40
String motorSet="";
byte byteRead;
int speedSet=0;

AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  myservo.write(90);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      byteRead=Serial.read();
      if(byteRead==97){turnLeft();}
      if(byteRead==100){turnRight();}
      if(byteRead==119){moveForward();}
      if(byteRead==115){moveBackward();}
      if(byteRead==120){moveStop();}
      Serial.write(byteRead);
      byteRead=0;
    }
    delay(500);
  
}

void moveForward(){
  motorSet="FORWARD";
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  for(speedSet=0;speedSet<MAX_SPEED;speedSet+=2){
    motor1.setSpeed(speedSet+MAX_SPEED_OFFSET);
    motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);;
    delay(5);
    
    }
  }

void moveBackward(){
  motorSet="BACKWARD";
    motor1.run(BACKWARD);
  motor2.run(BACKWARD);

  for(speedSet=0;speedSet<MAX_SPEED;speedSet+=2){
    motor1.setSpeed(speedSet+MAX_SPEED_OFFSET);
    motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);;
    delay(5);
    
    }
  }

  
void turnRight(){
  motorSet="RIGHT";
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  }


  void turnLeft(){
  motorSet="RIGHT";
    motor1.run(BACKWARD);
    motor2.run(FORWARD);

  }

  void moveStop(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    
    }

  

