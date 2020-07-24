/* Constants Definition */
const int distanceSensorTrigPin = 12;
const int distanceSensorEchoPin = 13;
/* The echo time does not seem to be completely linearly
 * dependant on the distance. The sound velocity constant 
 * around this value yields a good precision for certain 
 * interval of the range, but not the same precision for 
 * the whole range 4 to 400 cm. The number 0.032 results 
 * in a good precision for close distance from about
 * 6 to 30 cm.
 */
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
  /* Returns distance in cm.*/
  sendPulseMicroseconds(distanceSensorTrigPin, 10);
  // waiting for 8 cycles of US burst to pass
  delayMicroseconds(200); 
  unsigned long duration = pulseIn(distanceSensorEchoPin, HIGH, 100000) + 200;
  float distance = duration * speedOfSoundCentiMetersPerMicrosecond / 2;
  // sensor returns 3.2 cm if it cannot sense anything
  if(distance < 4) distance = 400;
  return distance;
}

void sendPulseMicroseconds(const int pin, unsigned int t)
{
  /* Send out t us long pulse */
  digitalWrite(pin, HIGH);
  delayMicroseconds(t);
  digitalWrite(pin, LOW);
}
