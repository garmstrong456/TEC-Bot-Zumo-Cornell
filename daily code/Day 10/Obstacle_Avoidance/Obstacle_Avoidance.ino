/*
   Wall Avoid
   Greg Armstrong, July 11th 2016

   License: CC BY-SA 4.0

   Drive forward until the distance sensor detects
   an obstacle. Once it does, back up and turn turn a
   random angle then continue driving forward.
*/

#include <ZumoMotors.h>

ZumoMotors motors;

void setup() {
}

void loop() {
    motors.setSpeeds(300, 300);         //Drive straight forward
    int distance = analogRead(A3);      //read the distance
    
    if (distance > 250) {               //test the distance (larger numbers = closer)
        motors.setSpeeds(-300, -300);   //back up
        delay(1000);                    //for 1 second
        motors.setSpeeds(-400, 400);    //turn
        delay(random(200, 500));        //for a random amount of time (.2 - .5 seconds)
    }
}
