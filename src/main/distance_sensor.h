/* Constants Definition */
const int distanceSensorTrigPin = 12;
const int distanceSensorEchoPin = 13;
const float speedOfSoundCentiMetersPerMicrosecond = 0.032;

/* Functions Declaration */
void setupDistanceSensor();
void sendPulseMicroseconds(const int pin, unsigned int t);
float getDistance();


/* Implementation */
void setupDistanceSensor()
{
  pinMode(distanceSensorTrigPin, OUTPUT);
  pinMode(distanceSensorEchoPin, INPUT);
}

float getDistance()
{
  /* Returns distance in m.*/
  sendPulseMicroseconds(distanceSensorTrigPin, 10);
  // waiting for 8 cycles of US burst to pass
  delayMicroseconds(200); 
  unsigned long duration = pulseIn(distanceSensorEchoPin, HIGH, 100000) + 200;
  float distance = duration * speedOfSoundCentiMetersPerMicrosecond / 2;
  return distance;
}

void sendPulseMicroseconds(const int pin, unsigned int t)
{
  /* Send out t us long pulse */
  digitalWrite(pin, HIGH);
  delayMicroseconds(t);
  digitalWrite(pin, LOW);
}
