#include "Vector3D.h"

Vector3D::Vector3D()
{
}

Vector3D::~Vector3D()
{
}

Vector3D::Vector3D(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float Vector3D::DotProduct(Vector3D _vectorOne, Vector3D _vectorTwo)
{
	float dotProduct = 0.0f;		

	dotProduct = (_vectorOne.x * _vectorTwo.x) + (_vectorOne.y * _vectorTwo.y) + (_vectorOne.z * _vectorTwo.z);

	return dotProduct;
}

Vector3D Vector3D::CrossProduct(Vector3D _vectorOne, Vector3D _vectorTwo)
{
	Vector3D crossProduct;

	return crossProduct;
}


