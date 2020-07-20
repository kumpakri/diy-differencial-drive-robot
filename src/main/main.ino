/*
* |ARDUINO PINS USAGE          |
* |----|-----------------------|
* |  2 | encoderRightPin       |
* |  3 | encoderLeftPin        |
* |  5 | motor2SpeedPin        |
* |  6 | motor1SpeedPin        |
* |  7 | motor1DirAPin         |
* |  8 | motor1DirBPin         |
* |  9 | motor2DirAPin         |
* | 10 | motor2DirBPin         |
* | 12 | distanceSensorTrigPin |
* | 13 | distanceSensorEchoPin |
*/

#include "drive_motors.h"
#include "encoder.h"
#include "distance_sensor.h"

void setup() {
  Serial.begin(9600);
  setupMotors();
  setupEncoders();
  setupDistanceSensor();
  //setVelocity(0, 0);
}

void loop() {
  Serial.println(getDistance());
}
