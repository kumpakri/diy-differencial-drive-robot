/* Constants Definition */
const int encoderRightPin = 2;
const int encoderLeftPin = 3;

const unsigned int slotsPerRev = 20;
const unsigned long updatePeriod = 1000; //ms

/* Variables */
long pulseCountEncoderRight = 0;
long pulseCountEncoderLeft = 0;
unsigned long lastUpdateTimeEncoderRight = 0;
unsigned long lastUpdateTimeEncoderLeft = 0;

float rpmEncoderRight = 0;
float rpmEncoderLeft = 0;

/* Functions Declaration */
void setupEncoders();
void incPulseCountEncoderRight();
void incPulseCountEncoderLeft();
void updateRPMEncoderRight();
void updateRPMEncoderLeft();
int getRPMRightWheel();
int getRPMLeftWheel();

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

void updateRPMEncoderRight()
{
  long now = millis();
  if(now > lastUpdateTimeEncoderRight + updatePeriod)  
  {
      lastUpdateTimeEncoderRight = now;
      rpmEncoderRight = float(pulseCountEncoderRight) * 60000.0 / (20.0 * updatePeriod);
      pulseCountEncoderRight = 0;
      //String msg("right: ");
      //msg += rpmEncoderRight;
      //Serial.println(msg);
  }
}

void updateRPMEncoderLeft()
{
  long now = millis();
  if(now > lastUpdateTimeEncoderLeft + updatePeriod)  
  {
      lastUpdateTimeEncoderLeft = now;
      rpmEncoderLeft = float(pulseCountEncoderLeft) * 60000.0 / (20.0 * updatePeriod);
      pulseCountEncoderLeft = 0;
      //String msg("left: ");
      //msg += rpmEncoderLeft;
      //Serial.println(msg);
  }
}

int getRPMRightWheel() { return rpmEncoderRight;}
int getRPMLeftWheel() { return rpmEncoderLeft;}
