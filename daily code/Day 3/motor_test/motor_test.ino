/*
   Motor Test
   Greg Armstrong, July 5th 2016

   License: CC BY-SA 4.0

   Drive the TEC-Bot back and forth at full speed
   This can be used to test the motor direction on your robot
   The user LED should be on while the robot moves forward and
   off while it moves backward
*/

#include <ZumoMotors.h>

#define LED_PIN 13

ZumoMotors motors;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  //If your robot turns in circles or moves backwards when it should be going forward uncomment
  //one or both of these lines

  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

}

void loop() {
  //Drive forward for 2 seconds
  motors.setLeftSpeed(400);
  motors.setRightSpeed(400);
  digitalWrite(LED_PIN, HIGH);      //Turn the LED on when the robot moves forward
  delay(2000);

  motors.setLeftSpeed(-400);
  motors.setRightSpeed(-400);
  digitalWrite(LED_PIN, LOW);      //Turn the LED off when the robot moves backward
  delay(2000);
}
