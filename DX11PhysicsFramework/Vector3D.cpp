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
	crossProduct.x = (_vectorOne.y * _vectorTwo.z) - (_vectorOne.z * _vectorTwo.y);
	crossProduct.y = (_vectorOne.z * _vectorTwo.x) - (_vectorOne.x * _vectorTwo.z);
	crossProduct.z = (_vectorOne.x * _vectorTwo.y) - (_vectorOne.y * _vectorTwo.x);

	return crossProduct;
}

float Vector3D::Magnitude(Vector3D _vector)
{
	float magnitude = sqrt(pow(_vector.x, 2) + pow(_vector.y, 2) + pow(_vector.z, 2));

	return magnitude;
}

Vector3D Vector3D::Normalize(Vector3D _vector)
{
	float vectorMag = Magnitude(_vector);
	Vector3D normalizedVector;
	normalizedVector.x = _vector.x / vectorMag;
	normalizedVector.y = _vector.y / vectorMag;
	normalizedVector.z = _vector.z / vectorMag;
	

	return normalizedVector;
}

Vector3D Vector3D::operator+(Vector3D _vector)
{
	Vector3D addedVectors;
	addedVectors.x = this->x + _vector.x;
	addedVectors.y = this->y + _vector.y;
	addedVectors.z = this->z + _vector.z;
	return addedVectors;
}

Vector3D Vector3D::operator*(Vector3D _vector)
{
	Vector3D multipliedVectors;
	multipliedVectors.x = this->x * _vector.x;
	multipliedVectors.y = this->y * _vector.y;
	multipliedVectors.z = this->z * _vector.z;
	return multipliedVectors;
}

Vector3D Vector3D::operator*(float _num)
{
	Vector3D scaledVector;
	scaledVector.x = this->x * _num;
	scaledVector.y = this->y * _num;
	scaledVector.z = this->z * _num;
	return scaledVector;
}

void Vector3D::operator=(Vector3D _vector)
{	
	this->x = _vector.x;
	this->y = _vector.y;
	this->z = _vector.z;	
}

void Vector3D::operator+=(Vector3D _vector)
{
	this->x += _vector.x;
	this->y += _vector.y;
	this->z += _vector.z;
}

//void Vector3D::operator/(Vector3D _vector)
//{
//	this->x = this->x / _vector.x;
//	this->y = this->y / _vector.y;
//	this->z = this->z / _vector.z;
//}

Vector3D Vector3D::operator/(float _num)
{
	Vector3D newVector = Vector3D(0, 0, 0);
	newVector.x = this->x / _num;
	newVector.y = this->y / _num;
	newVector.z = this->z / _num;
	return newVector;
}






