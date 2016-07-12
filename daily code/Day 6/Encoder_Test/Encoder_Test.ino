/*
    Encoder Test
    Greg Armstrong, July 11th 2016

    License: CC BY-SA 4.0

    Test to make sure you have the encoders plugged in correctly.

    NOTE: this program will only work properly with the Seeeduino pluged in via USB

    Directions:
    1) Run the program then open the Serial Monitor
    2) Carefully turn the treads one at a time:
        a) when you turn the left tread you should see the left position change and vice versa
        b) if the numbers are reversed then swap both sets of encoder data pins (A0, A1 --> A4, A5)
    3) Carefully turn the left tread forward (as if the motor was driving the robot forward)
        a) The left position should increase
        b) if it doesn't swap the encoders two wires
    4) repeat step 3 with the right motor
*/

#include <Encoder.h>

Encoder leftEncoder(A4, A5);
Encoder rightEncoder(A1, A0);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int leftPosition = leftEncoder.read();
    int rightPosition = rightEncoder.read();

    Serial.print("Left Position: "); Serial.print(leftPosition); Serial.print("\t");
    Serial.print("Right Position: "); Serial.print(rightPosition); Serial.println();
}
