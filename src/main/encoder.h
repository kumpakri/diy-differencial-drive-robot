/* Constants Definition */
const int encoderRightPin = 2;
const int encoderLeftPin = 3;

const unsigned int slotsPerRev = 20;
const unsigned long updatePeriod = 1000; //ms

const double pi = 3.1415;

/* Variables */
long pulseCountEncoderRight = 0;
long pulseCountEncoderLeft = 0;
unsigned long lastUpdateTimeEncoders = 0;
float rpmEncoderRight = 0;
float rpmEncoderLeft = 0;

/* Functions Declaration */
void setupEncoders();
void incPulseCountEncoderRight();
void incPulseCountEncoderLeft();
void updateRPMEncoders();
struct wheelProperty getRPM();
struct wheelProperty getRadiansPerSecond();

/* Implementation */
void setupEncoders()
{
  pinMode(encoderRightPin, INPUT);
  pinMode(encoderLeftPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderRightPin), incPulseCountEncoderRight, RISING);
  attachInterrupt(digitalPinToInterrupt(encoderLeftPin), incPulseCountEncoderLeft, RISING);
}

void incPulseCountEncoderRight()
{
  if(getFlagMotorRightFWD())
  {
    pulseCountEncoderRight++;
  } else {
    pulseCountEncoderRight--;  
  }
}

void incPulseCountEncoderLeft()
{
  if(getFlagMotorLeftFWD())
  {
    pulseCountEncoderLeft++;
  } else {
    pulseCountEncoderLeft--;  
  }
}

void updateEncoders()
{
  long now = millis();
  if(now > lastUpdateTimeEncoders + updatePeriod)  
  {
      lastUpdateTimeEncoders = now;
      rpmEncoderRight = float(pulseCountEncoderRight) * 60000.0 / (20.0 * updatePeriod);
      rpmEncoderLeft = float(pulseCountEncoderLeft) * 60000.0 / (20.0 * updatePeriod);
      pulseCountEncoderRight = 0;
      pulseCountEncoderLeft = 0;
  }
}

struct wheelProperty getRPM() 
{ 
  struct wheelProperty rpm;
  rpm.right = rpmEncoderRight;
  rpm.left = rpmEncoderLeft;
  
  return rpm;
}

struct wheelProperty getRadiansPerSecond()
/*
 * Returns actaul speed of the wheels in radians per second.
*/
{
  struct wheelProperty radiansPerSecond;
  radiansPerSecond.right = getRPM().right / (2 * pi * 60);
  radiansPerSecond.left = getRPM().left / (2 * pi * 60);

  return radiansPerSecond;
}
