#include <Wire.h>
#include <LSM303.h>

//Declare the compass/accelerometer object
LSM303 compass;

void setup() {
    //Begin serial communication 
    Serial.begin(9600);

    //Start communication with the compass
    Wire.begin();
    compass.init();
    compass.enableDefault();
}

void loop() {
    //This command pulls data from the compass/acc sensor
    //compass.a.x  =  acceleration in the x direction   compass.m.x  =  mag field in the x direction
    //compass.a.y  =  acceleration in the y direction   compass.m.y  =  mag field in the y direction
    //compass.a.z  =  acceleration in the z direction   compass.m.z  =  mag field in the z direction
    compass.read();

    //Detect orientation
    Serial.print("I am currently: ");
    if (compass.a.z > 10000) {          //az > 10000 means gravity is pointing down relative to the robot
        Serial.print("right side up");
    } else if (compass.a.z < -10000) {  //az < -10000 means gravity is pointing up relative to the robot
        Serial.print("upside down!");
    } else {
        Serial.print("flipping over!!!");   //anything else is somewhere in between
    }

    //Display all the data acquired on the serial monitor
    Serial.print("\t\t");
    Serial.print("ax: "); Serial.print(compass.a.x); Serial.print("\t");
    Serial.print("ay: "); Serial.print(compass.a.y); Serial.print("\t");
    Serial.print("az: "); Serial.print(compass.a.z); Serial.print("\t");
    Serial.print("mx: "); Serial.print(compass.m.x); Serial.print("\t");
    Serial.print("my: "); Serial.print(compass.m.y); Serial.print("\t");
    Serial.print("mz: "); Serial.print(compass.m.z); Serial.print("\t");
    Serial.println();
}
