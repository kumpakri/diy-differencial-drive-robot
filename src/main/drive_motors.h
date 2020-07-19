/* Constants Definition */
const int motor1SpeedPin = 6;
const int motor2SpeedPin = 5;

const int motor1DirAPin = 7;
const int motor1DirBPin = 8;
const int motor2DirAPin = 9;
const int motor2DirBPin = 10;

/* Variables */
int flagMotor1FWD = 1;
int flagMotor2FWD = 1;

/* Functions Declaration */
void setupMotors();
void setVelocity(int rightWheelSpeed, int leftWheelSpeed);
int getFlagMotorRightFWD();
int getFlagMotorLeftFWD();

/* Implementation */
void setupMotors()
{
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  pinMode(motor1DirAPin, OUTPUT);
  pinMode(motor1DirBPin, OUTPUT);
  pinMode(motor2DirAPin, OUTPUT);
  pinMode(motor2DirBPin, OUTPUT);
}

void setVelocity(int rightWheelSpeed, int leftWheelSpeed)
{
  /*
  * Accepts PWM velocity value 0-255 for forward movement
  * and (-255)-0 for backward movement.
  */
  if(rightWheelSpeed >= 0)
  { // rotate forward (clockwise)
    digitalWrite(motor1DirAPin, HIGH); 
    digitalWrite(motor1DirBPin, LOW);
    flagMotor1FWD = 1;
  } else { // rotate backward (counter-clockwise)
    digitalWrite(motor1DirAPin, LOW); 
    digitalWrite(motor1DirBPin, HIGH);
    flagMotor1FWD = 0;
  }

  if(leftWheelSpeed >= 0)
  { // rotate forward (counter-clockwise)
    digitalWrite(motor2DirAPin, HIGH); 
    digitalWrite(motor2DirBPin, LOW);
    flagMotor2FWD = 1;
  } else { // rotate backward (clockwise)
    digitalWrite(motor2DirAPin, LOW); 
    digitalWrite(motor2DirBPin, HIGH);
    flagMotor2FWD = 0;
  }
  analogWrite(motor1SpeedPin, abs(rightWheelSpeed));
  analogWrite(motor2SpeedPin, abs(leftWheelSpeed));
}

int getFlagMotorRightFWD() {return flagMotor1FWD;}
int getFlagMotorLeftFWD() {return flagMotor2FWD;}
