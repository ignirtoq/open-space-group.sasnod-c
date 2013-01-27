#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct
{
	void* this;
	PhysicalState* physicalStateRef;
	void (*update)(void*, double dt);
} ISimObject;

typedef void* Simulation;

extern Simulation Simulation_Create();
extern void Simulation_Destroy(Simulation sim);
extern void Simulation_Init(Simulation sim, const char* configFile);
extern void Simulation_Step(Simulation sim);

#endif
