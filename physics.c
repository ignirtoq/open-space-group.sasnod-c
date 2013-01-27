#include <physics.h>
#include <geometry.h>
#include <constants.h>
#include <math.h>

void PhysicalState_Update(PhysicalState *state, VectorObservable force, VectorObservable torque, double dt)
{
}

Vector Physics_GetGravitationalForce(Vector pos, double mass)
{
	double positionLengthSquared = Vector_GetLengthSquared(pos);
	double positionLength = sqrt(positionLengthSquared);
	return Vector_Scale(position, -GRAVITATIONAL_CONSTANT * MASS_OF_EARTH * mass / (positionLengthSquared * positionLength));
}
