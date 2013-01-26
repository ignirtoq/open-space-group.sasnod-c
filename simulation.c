#include <simulation.h>
#include <stddef.h>

typedef struct
{
	double timeStep;
} _Simulation;

Simulation Simulation_Create()
{
	_Simulation* sim = (_Simulation*)malloc(sizeof(_Simulation));
	return (Simulation)sim;
}

void Simulation_Destroy(Simulation sim)
{
	free(sim);
}

void Simulation_Init(Simulation sim, const char* configFile)
{
}

void Simulation_Step(Simulation sim)
{
}

#endif
