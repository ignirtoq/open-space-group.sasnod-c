#ifndef PHYSICS_H
#define PHYSICS_H

#include <geometry.h>

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
 
#endif
