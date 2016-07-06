/*
   Nonblocking Blinky
   Greg Armstrong, July 5th 2016

   License: CC BY-SA 4.0

   Turn the user LED on and off without using the delay command
   This allows the Arduino processor to do other things while the LED is blinking
*/

const int BLINK_TIME = 500;   //Delay between the LED turning off and on
long lastBlinkTime;           //time when the LED last changed state
boolean LEDState;             //current state of the LED (HIGH or LOW)


void setup() {
  Serial.begin(9600);   //Initialize Serial communication
  pinMode(13, OUTPUT);  //Setup pin 13 as an output


  digitalWrite(13, HIGH);   //Start with the LED on
  lastBlinkTime = millis(); //record when the LED turned on
}

void loop() {

  if (millis() > lastBlinkTime + BLINK_TIME) {  //Check to see if BLINK_TIME milliseconds have ellapsed
    LEDState = !LEDState;         //switch the state of the LED (HIGH --> LOW or LOW --> HIGH)
    digitalWrite(13, LEDState);   //apply the changes to the LED
    lastBlinkTime = millis();     //record the time
  }

}
