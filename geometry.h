#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct
{
	double x,y,z;
} Vector;

extern Vector Vector_Add(Vector a, Vector b);
extern Vector Vector_Subtract(Vector a, Vector b);
extern Vector Vector_Scale(Vector a, double s);
extern double Vector_Dot(Vector a, Vector b);

#endif
