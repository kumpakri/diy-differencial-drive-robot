/*
* |ARDUINO PINS USAGE   |
* |----|----------------|
* |  2 | motor1DirAPin  |
* |  3 | motor1DirBPin  |
* |  4 | motor2DirAPin  |
* |  5 | motor1SpeedPin |
* |  6 | motor2SpeedPin |
* |  7 | motor2DirBPin  |
*/

#include "drive_motors.h"

void setup() {
  // put your setup code here, to run once:
  setup_motors();
  set_velocity(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
