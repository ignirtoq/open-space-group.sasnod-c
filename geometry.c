#include <geometry.h>
#include <math.h>
#include <assert.h>

Vector Vector_Add(Vector a, Vector b)
{
	return (Vector){a.x+b.x, a.y+b.y, a.z+b.z};
}

Vector Vector_Subtract(Vector a, Vector b)
{
	return (Vector){a.x-b.x, a.y-b.y, a.z-b.z};
}

Vector Vector_Scale(Vector a, double s)
{
	return (Vector){a.x * s, a.y * s, a.z * s};
}

double Vector_Dot(Vector a, Vector b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

double Vector_GetLengthSquared(Vector a)
{
	return Vector_Dot(a,a);
}

double Vector_GetLength(Vector a)
{
	return sqrt(Vector_GetLengthSquared(a));
}

Vector Vector_Normalize(Vector a)
{
	double length = Vector_GetLength(a);
	return (Vector){a.x/length, a.y/length, a.z/length};
}

Vector Vector_Cross(Vector a, Vector b)
{
	return (Vector){a.y*b.z - b.y*a.z, a.z*b.x - b.z*a.x, a.x*b.y - b.x*a.y};
}

Vector Vector_ProjectOnto(Vector a, Vector b)
{
	if(Vector_GetLengthSquared(b) == 0.0)
		return (Vector){0.0,0.0,0.0};

	return Vector_Scale(b, Vector_Dot(a,b)/Vector_GetLengthSquared(b));
}

double Vector_GetComponentInDirection(Vector a, Vector b)
{
	if(Vector_GetLengthSquared(b) == 0.0)
		return 0.0;

	return Vector_GetLength(Vector_ProjectedOnto(a,b));
}

Quaternion Quaternion_Add(Quaternion a, Quaternion b)
{
	return (Quaternion){a.scalar+b.scalar, Vector_Add(a.vector,b.vector)};
}

Quaternion Quaternion_Subtract(Quaternion a, Quaternion b)
{
	return (Quaternion){a.scalar-b.scalar, Vector_Subtract(a.vector,b.vector)};
}

Quaternion Quaternion_Scale(Quaternion a, double s)
{
	return (Quaternion){a.scalar*s, Vector_Scale(a.vector,s)};
}

Quaternion Quaternion_Multiply(Quaternion a, Quaternion b)
{
	Vector scaledVectorA = Vector_Scale(a.vector, b.scalar);
	Vector scaledVectorB = Vector_Scale(b.vector, a.scalar);
	Vector aCrossB = Vector_Cross(a.vector, b.vector);

	return (Quaternion){a.scalar*b.scalar-aCrossB, Vector_Add(scaledVectorA, Vector_Add(scaledVectorB, aCrossB))};
}

Quaternion Quaternion_Conjugate(Quaternion a)
{
	return (Quaternion){a.scalar, Vector_Scale(a, -1.0)};
}

double Quaternion_GetModulusSquared(Quaternion a)
{
	return a.scalar*a.scalar + Vector_GetLengthSquared(a.vector);
}

double Quaternion_GetModulus(Quaternion a)
{
	return sqrt(Quaternion_GetModulusSquared(a));
}

Quaternion Quaternion_GetFromMatrix(Matrix a)
{
	if(a.a00 + a.a11 + a.a22 > 0)
	{
		double radical = 2 * sqrt(1 + a.a00 + a.a11 + a.a22);
		double scalar = 0.25 * radical;
		double x = (a.a21 - a.a12) / radical;
		double y = (a.a02 - a.a20) / radical;
		double z = (a.a10 - a.a01) / radical;
	}
	else
		assert(0);
}

double Matrix_GetDeterminant(Matrix a)
{
	return (a.a00*a.a11*a.a22 + a01*a12*a20 + a02*a10*a21) - (a.a02*a.a11*a.a20 + a.a12*a.a21*a.a00 + a.a22*a.a01*a.a10);
}

Matrix Matrix_Invert(Matrix a)
{
	double aDet = Matrix_GetDeterminant(a);
	if(aDet != 0.0)
	{
		double invDet = 1.0/aDet;
		double a00 = invDet * (a.a11*a.a22 - a.a12*a.a21);
		double a01 = invDet * (a.a02*a.a21 - a.a01*a.a22);
		double a02 = invDet * (a.a01*a.a12 - a.a02*a.a11);

		double a10 = invDet * (a.a12*a.a20 - a.a10*a.a22);
		double a11 = invDet * (a.a00*a.a22 - a.a02*a.a20);
		double a12 = invDet * (a.a02*a.a10 - a.a00*a.a12);

		double a20 = invDet * (a.a10*a.a21 - a.a11*a.a20);
		double a21 = invDet * (a.a01*a.a20 - a.a00*a.a21);
		double a22 = invDet * (a.a00*a.a11 - a.a01*a.a10);

		return (Matrix){a00,a01,a02,a10,a11,a12,a20,a21,a22};
	}
	else
		assert(0 && "Tried to invert singular matrix.");
}

Vector Matrix_MultiplyVector(Matrix a, Vector b)
{
	return (Vector){a.a00*b.x + a.a01*b.y + a.a02*b.z, a.a10*b.x + a.a11*b.y + a.a12*b.z, a.a20*b.x + a.a21*b.y + a.a22**b.z};
}

Matrix Matrix_MultiplyMatrix(Matrix a, Matrix b)
{
	Vector row0 = (Vector){a.a00,a.a01,a.a02};
	Vector row1 = (Vector){a.a10,a.a11,a.a12};
	Vector row2 = (Vector){a.a20,a.a21,a.a22};

	Vector col0 = (Vector){b.a00,b.a10,b.a20};
	Vector col1 = (Vector){b.a01,b.a11,b.a21};
	Vector col2 = (Vector){b.a02,b.a12,b.a22};

	double a00 = Vector_Dot(row0,col0);
	double a01 = Vector_Dot(row0,col1);
	double a02 = Vector_Dot(row0,col2);
	double a10 = Vector_Dot(row1,col0);
	double a11 = Vector_Dot(row1,col1);
	double a12 = Vector_Dot(row1,col2);
	double a20 = Vector_Dot(row2,col0);
	double a21 = Vector_Dot(row2,col1);
	double a22 = Vector_Dot(row2,col2);

	return (Matrix){a00,a01,a02,a10,a11,a12,a20,a21,a22};
}

Matrix Matrix_GetFromQuaternion(Quaternion a)
{
	double a00 = a.scalar*a.scalar + a.vector.x*a.vector.x - a.vector.y*a.vector.y - a.vector.z*a.vector.z;
	double a11 = a.scalar*a.scalar - a.vector.x*a.vector.x + a.vector.y*a.vector.y - a.vector.z*a.vector.z;
	double a22 = a.scalar*a.scalar - a.vector.x*a.vector.x - a.vector.y*a.vector.y + a.vector.z*a.vector.z;

	double a01 = 2*a.vector.x*a.vector.y - 2*a.scalar*a.vector.z;
	double a10 = 2*a.vector.x*a.vector.y + 2*a.scalar*a.vector.z;

	double a02 = 2*a.vector.x*a.vector.z + 2*a.scalar*a.vector.y;
	double a20 = 2*a.vector.x*a.vector.z - 2*a.scalar*a.vector.y;

	double a12 = 2*a.vector.y*a.vector.z - 2*a.scalar*a.vector.x;
	double a21 = 2*a.vector.y*a.vector.z + 2*a.scalar*a.vector.x;

	return (Matrix){a00,a01,a02,a10,a11,a12,a20,a21,a22};
}
