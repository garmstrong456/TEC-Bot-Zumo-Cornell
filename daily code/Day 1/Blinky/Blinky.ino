/*
Blinky
Greg Armstrong, July 4th 2016

This program will repeatedly turn the onboard LED on and off
 */

void setup() {
  Serial.begin(9600);   //Initialize Serial communication
  pinMode(13, OUTPUT);  //Setup pin 13 as an output
}

void loop() {
  digitalWrite(13, HIGH);     //Turn on the LED on pin 13
  Serial.println("ON");   //Tell the PC that the LED is on
  delay(200);            //Wait 1s (1000ms)
  digitalWrite(13, LOW);      //Turn the LED on pin 13 off
  Serial.println("OFF");  //Tell the PC that the LED is off
  delay(200);            //Wait 1s (1000ms)
}
