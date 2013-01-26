#include <geometry.h>

Vector Vector_Add(Vector a, Vector b)
{
	return (Vector){a.X+b.X, a.Y+b.Y, a.Z+b.Z};
}

Vector Vector_Subtract(Vector a, Vector b);
Vector Vector_Scale(Vector a, double s);
double Vector_Dot(Vector a, Vector b);
