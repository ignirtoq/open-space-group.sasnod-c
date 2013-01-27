#ifndef ENVIRONMENTS_H
#define ENVIRONMENTS_H

#include <geometry.h>

typedef struct
{
	void* this;
	double (*temperature)(void*, Vector position);
	double (*pressure)(void*, Vector position);
	double (*density)(void*, Vector position);
} IEnvironmentService;

#endif
