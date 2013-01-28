#ifndef PHYSICS_H
#define PHYSICS_H

#include <geometry.h>
#include <environments.h>

typedef struct
{
    Vector Position;
    Vector Velocity;
    double InverseMass;
    Quaternion Orientation;
    Vector AngularMomentum;
    Matrix InverseInertiaTensor;
} PhysicalState;

typedef struct
{
	Vector (*func)(void*, PhysicalState*);
	void* state;
} VectorObservable;

void PhysicalState_Update(PhysicalState *state, VectorObservable force, VectorObservable torque, double dt);

Vector Physics_GetGravitationalForce(Vector pos, double mass);
Vector Physics_GetDragForce(Vector pos, Vector vel, double crossSectionalArea, double dragCoeff, IEnvironmentService env);
Vector Physics_GetBuoyantForce(Vector pos, double mass, double volume, IEnvironmentService env);
 
#endif
