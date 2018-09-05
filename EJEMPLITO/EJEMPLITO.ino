#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup( ){
 motor1.setSpeed(0);
 motor4.setSpeed(0);
}
void loop(){
  motor1.run(FORWARD);
  motor4.run(BACKWARD);
  
}

