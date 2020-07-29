/* Constants Definition */
double R = 32.5;  // mm - radius of the drive wheel
double L = 129; // mm - distance between centers of wheels


/* Functions Declaration */
struct wheelProperty getWheelAngularVelocities(
  double robotLinearVelocity,
  double robotAngularVelocity);


/* Implementation */
struct wheelProperty getWheelAngularVelocities(
  double robotLinearVelocity,
  double robotAngularVelocity)
{
  /**
  * Returns the desired wheel angular velocities
  * in radians per second.
  */
  struct wheelProperty wheelAngularVelocities;
  wheelAngularVelocities.right = (2 * robotLinearVelocity + L * robotAngularVelocity) / (2 * R);
  wheelAngularVelocities.left = (2 * robotLinearVelocity - L * robotAngularVelocity) / (2 * R);
}
