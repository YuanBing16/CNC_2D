// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!
// modified by Soleh Al Yunus, success!

#include <AFMotor.h>
#include <Servo.h> 

// DC motor on M2,M4
AF_DCMotor motor(2,4);
// DC hobby servo
Servo servo1;
// Stepper motor on M1+M2+M3+M4 48 steps per revolution
AF_Stepper stepperX(48, 1);
AF_Stepper stepperY(48, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor stepper and servo tes!");
  
  // turn on servo
  servo1.attach(10);
   
  // turn on motor
  motor.setSpeed(50);
  motor.run(RELEASE);
}
  int i;

// Test Stepper X,Y and servo 8x then CNC is Stop!

void loop() {

   motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    servo1.write(40);
    motor.setSpeed(i);  
    delay(2);
    stepperX.step(1, FORWARD, DOUBLE);
 }
  
  for (i=255; i!=0; i--) {
    servo1.write(i-255);
    motor.setSpeed(i);  
    stepperY.step(1, FORWARD, DOUBLE);
    delay(2);
 }

  for (i=0; i<255; i++) {
    servo1.write(40);
    motor.setSpeed(i);  
    stepperX.step(1, BACKWARD, DOUBLE);
    delay(2);
 }
 
  for (i=255; i!=0; i--) {
    servo1.write(i-255);
    motor.setSpeed(i);  
    stepperY.step(1, BACKWARD, DOUBLE);
    delay(2);
  }
}
