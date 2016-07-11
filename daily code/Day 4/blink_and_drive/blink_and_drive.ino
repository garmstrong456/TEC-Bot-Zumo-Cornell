/*
   Blink and Drive
   Greg Armstrong, July 5th 2016

   License: CC BY-SA 4.0

  Drive the TEC-Bot back and forth while blinking the LED at a different rate
*/

#include <ZumoMotors.h>

ZumoMotors motors;

const int BLINK_TIME = 700, MOTOR_TIME = 2000;
long nextBlinkTime = 0, nextMotorTime = 0;
boolean LEDState = HIGH;
int motorSpeed = -400;

void setup() {
  pinMode(13, OUTPUT);

  // uncomment one or both of the following lines if your motors need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
}

void loop() {

  //Check to see if the LED should blink
  if (millis() >= nextBlinkTime) {
    LEDState = !LEDState;
    digitalWrite(13, LEDState);
    nextBlinkTime = millis() + BLINK_TIME;
  }

  //Check to see if the motor should reverse direction
  if (millis() >= nextMotorTime) {
    motorSpeed = -motorSpeed;
    motors.setLeftSpeed(motorSpeed);
    motors.setRightSpeed(motorSpeed);
    nextMotorTime = millis() + MOTOR_TIME;
  }

}
