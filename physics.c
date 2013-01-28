#include <physics.h>
#include <geometry.h>
#include <constants.h>
#include <math.h>
#include <environments.h>

void PhysicalState_Update(PhysicalState *state, VectorObservable force, VectorObservable torque, double dt)
{
}

Vector Physics_GetGravitationalForce(Vector pos, double mass)
{
	double positionLengthSquared = Vector_GetLengthSquared(pos);
	double positionLength = sqrt(positionLengthSquared);
	return Vector_Scale(pos, -GRAVITATIONAL_CONSTANT * MASS_OF_EARTH * mass / (positionLengthSquared * positionLength));
}

Vector Physics_GetDragForce(Vector pos, Vector vel, double crossSectionalArea, double dragCoeff, IEnvironmentService env)
{
  Vector RotatingVelocity = (Vector){vel.x + pos.y * ANGULAR_VELOCITY_OF_EARTH, vel.y - pos.x * ANGULAR_VELOCITY_OF_EARTH, vel.z};
  return Vector_Scale(RotatingVelocity, -0.5 * env.density(pos) * dragCoef * crossSectionalArea * Velocity_GetLength(RotatingVelocity));
}

Vector BuoyantForce(Vector pos, double mass, double volume, IEnvironmentService env)
{
        return Vector_Scale(Physics_GetGravitationalForce(pos, mass), -2 * env.density(pos) * volume / (mass + env.density(pos) * volume));
}

