/*
   Drive Straight
   Greg Armstrong, July 11th 2016

   License: CC BY-SA 4.0

   Use the encoders and PID control to drive in a straight line. Small differences in friction between two
   motors on a robot can result in slightly different rotation speed for a given speed setting. This program
   uses the built-in encoders (rotation sensors) to measure the actual speed of rotation and adjusts
   the outputs accordingly.

   To make sure you have the encoders plugged in correctly run the "Encoder_Test.ino" program before running
   this one.
*/

#include <Encoder.h>
#include <ZumoMotors.h>

//Declare the encoder objects:
Encoder leftEncoder(A4, A5);
Encoder rightEncoder(A1, A0);

ZumoMotors motors;

void setup() {

    //motors.flipLeftMotor(true);
    //motors.flipRightMotor(true);
}


//****PID Control Constants****
double kp = .1;
double kd = 0;

//******Max Speed******
int totalSpeed = 200

long leftPosition = 0, rightPosition = 0;
long error, lastError = 0;
int speedCorrection = 0;

void loop() {
    //Read the encoder position
    leftPosition = leftEncoder.read();
    rightPosition = rightEncoder.read();

    //Calculate the error
    error = leftPosition - rightPosition;

    //Calculate the correction
    speedCorrection = kp*error + kd*(error - lastError);

    //Record the error for the next cycle
    lastError = error;

    //Calculate the corrected speeds
    int leftSpeed = totalSpeed - speedCorrection;
    int rightSpeed = totalSpeed + speedCorrection;

    //Force the speeds to be between 0 and 400
    leftSpeed = constrain(leftSpeed, 0, 400);
    rightSpeed = constrain(rightSpeed, 0, 400);

    //set the motors
    motors.setSpeeds(leftSpeed, rightSpeed);
}
