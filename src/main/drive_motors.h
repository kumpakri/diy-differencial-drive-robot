const int motor1SpeedPin = 6;
const int motor2SpeedPin = 5;

const int motor1DirAPin = 4;
const int motor1DirBPin = 7;
const int motor2DirAPin = 2;
const int motor2DirBPin = 3;


void setup_motors()
{
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
  pinMode(motor1DirAPin, OUTPUT);
  pinMode(motor1DirBPin, OUTPUT);
  pinMode(motor2DirAPin, OUTPUT);
  pinMode(motor2DirBPin, OUTPUT);
  Serial.begin(9600);
}

void set_velocity(int right_wheel_speed, int left_wheel_speed)
{
  /*
  * Accepts PWM velocity value 0-255 for forward movement
  * and (-255)-0 for backward movement.
  */
  if(right_wheel_speed >= 0)
  { // rotate forward (clockwise)
    digitalWrite(motor1DirAPin, HIGH); 
    digitalWrite(motor1DirBPin, LOW);
  } else { // rotate backward (counter-clockwise)
    digitalWrite(motor1DirAPin, LOW); 
    digitalWrite(motor1DirBPin, HIGH);
  }

  if(left_wheel_speed >= 0)
  { // rotate forward (clockwise)
    digitalWrite(motor2DirAPin, HIGH); 
    digitalWrite(motor2DirBPin, LOW);
  } else { // rotate backward (counter-clockwise)
    digitalWrite(motor2DirAPin, LOW); 
    digitalWrite(motor2DirBPin, HIGH);
  }
  analogWrite(motor1SpeedPin, abs(right_wheel_speed));
  analogWrite(motor2SpeedPin, abs(left_wheel_speed));
}
