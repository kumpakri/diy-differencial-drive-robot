/* Constants Definition */
const int sensorSelect0 = 4;
const int sensorSelect1 = 11;


/* Functions Declaration */
void setupMultiplexer();
struct distances getAllDistances();
void selectSensorAhead();
void selectSensorRight();
void selectSensorLeft();


/* Implementation */
struct distances
{
  double aheadSensorDistance;
  double rightSensorDistance;
  double leftSensorDistance;
};

void setupMultiplexer()
{
  pinMode(sensorSelect0, OUTPUT);
  pinMode(sensorSelect1, OUTPUT);
}

struct distances getAllDistances()
{
  struct distances distances;
  selectSensorAhead();
  distances.aheadSensorDistance = getDistance();
  selectSensorRight();
  distances.rightSensorDistance = getDistance();
  selectSensorLeft();
  distances.leftSensorDistance = getDistance();

  return distances;
}

void selectSensorAhead()
{
  digitalWrite(sensorSelect0, LOW); 
  digitalWrite(sensorSelect1, LOW); 
}

void selectSensorRight()
{
  digitalWrite(sensorSelect0, HIGH); 
  digitalWrite(sensorSelect1, LOW); 
}

void selectSensorLeft()
{
  digitalWrite(sensorSelect0, LOW); 
  digitalWrite(sensorSelect1, HIGH); 
}
