#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct
{
	double x,y,z;
} Vector;

typedef struct
{
	double scalar;
	Vector vector;
} Quaternion;

typedef struct
{
	double a00, a01, a02;
	double a10, a11, a12;
	double a20, a21, a22;
} Matrix;

extern Vector Vector_Add(Vector a, Vector b);
extern Vector Vector_Subtract(Vector a, Vector b);
extern Vector Vector_Scale(Vector a, double s);
extern double Vector_Dot(Vector a, Vector b);
extern double Vector_GetLengthSquared(Vector a);
extern double Vector_GetLength(Vector a);
extern Vector Vector_Normalize(Vector a);
extern Vector Vector_Cross(Vector a, Vector b);
extern Vector Vector_ProjectOnto(Vector a, Vector b);
extern double Vector_GetComponentInDirection(Vector a, Vector b);

extern Quaternion Quaternion_Add(Quaternion a, Quaternion b);
extern Quaternion Quaternion_Subtract(Quaternion a, Quaternion b);
extern Quaternion Quaternion_Scale(Quaternion a, double s);
extern Quaternion Quaternion_Multiply(Quaternion a, Quaternion b);
extern Quaternion Quaternion_Conjugate(Quaternion a);
extern double Quaternion_GetModulusSquared(Quaternion a);
extern double Quaternion_GetModulus(Quaternion a);
extern Quaternion Quaternion_GetFromAxisAngle(Vector axis, double angle);
extern Quaternion Quaternion_GetFromMatrib(Matrix a);

extern double Matrix_GetDeterminant(Matrix a);
extern Matrix Matrix_Invert(Matrix a);
extern Vector Matrix_MultiplyVector(Matrix a, Vector b);
extern Matrix Matrix_MultiplyMatrix(Matrix a, Matrix b);
extern Matrix Matrix_GetFromQuaternion(Quaternion a);

#endif
