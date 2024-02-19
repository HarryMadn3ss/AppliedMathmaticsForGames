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

Vector3D Vector3D::Zero()
{
	return Vector3D(0.0f, 0.0f, 0.0f);
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

float Vector3D::Magnitude()
{
	float magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

	return magnitude;
}

Vector3D Vector3D::Normalize()
{
	float vectorMag = Magnitude();

	if (vectorMag == 0) return Vector3D(0,0,0);

	Vector3D normalizedVector = Vector3D(0,0,0);
	normalizedVector.x = this->x / vectorMag;
	normalizedVector.y = this->y / vectorMag;
	normalizedVector.z = this->z / vectorMag;	

	return normalizedVector;
}

Vector3D Vector3D::Clamp(Vector3D max, Vector3D min)
{
	Vector3D clampedVector;
	if (this->x >= max.x) clampedVector.x = max.x;
	else if (this->x < min.x) clampedVector.x = min.x;
	else clampedVector.x = this->x;

	if (this->y > max.y) clampedVector.y = max.y;
	else if (this->y < min.y) clampedVector.y = min.y;
	else clampedVector.y = this->y;

	if (this->z > max.z) clampedVector.z = max.z;
	else if (this->z < min.z) clampedVector.z = min.z;
	else clampedVector.z = this->z;

	return clampedVector;
}

Vector3D Vector3D::Inverse()
{
	Vector3D inversed;
	inversed.x = -this->x;
	inversed.y = -this->y;
	inversed.z = -this->z;
	return inversed;
}

Vector3D Vector3D::operator+(Vector3D _vector)
{
	Vector3D addedVectors;
	addedVectors.x = this->x + _vector.x;
	addedVectors.y = this->y + _vector.y;
	addedVectors.z = this->z + _vector.z;
	return addedVectors;
}

Vector3D Vector3D::operator+(float _scalar)
{
	Vector3D addedVectors;
	addedVectors.x = this->x + _scalar;
	addedVectors.y = this->y + _scalar;
	addedVectors.z = this->z + _scalar;
	return addedVectors;	
}

Vector3D Vector3D::operator-(Vector3D _vector)
{
	Vector3D subVectors;
	subVectors.x = this->x - _vector.x;
	subVectors.y = this->y - _vector.y;
	subVectors.z = this->z - _vector.z;
	return subVectors;
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

bool Vector3D::operator==(Vector3D _vector)
{
	if (this->x == _vector.x && this->y == _vector.y && this->z == _vector.z) return true;
	else return false;
}

bool Vector3D::operator==(float _scalar)
{
	if (this->x == _scalar && this->y == _scalar && this->z == _scalar) return true;
	else return false;
}

void Vector3D::operator+=(Vector3D _vector)
{
	this->x += _vector.x;
	this->y += _vector.y;
	this->z += _vector.z;
}

void Vector3D::operator+=(float _scalar)
{
	this->x += _scalar;
	this->y += _scalar;
	this->z += _scalar;
}

void Vector3D::operator*=(float _scalar)
{
	this->x *= _scalar;
	this->y *= _scalar;
	this->z *= _scalar;
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

bool Vector3D::operator!=(Vector3D _vector)
{
	if (this->x != _vector.x || this->y != _vector.y || this->z != _vector.z) return true;
	else return false;	
}

bool Vector3D::operator>(Vector3D _vector)
{
	if (this->x > _vector.x && this->y > _vector.y && this->z > _vector.z) return true;
	else return false;
}

bool Vector3D::operator>(float _scalar)
{
	if (this->x > _scalar && this->y > _scalar && this->z > _scalar) return true;
	else return false;
}

bool Vector3D::operator<(Vector3D _vector)
{
	if (this->x < _vector.x && this->y < _vector.y && this->z < _vector.z) return true;
	else return false;
}

bool Vector3D::operator<(float _scalar)
{
	if (this->x < _scalar && this->y < _scalar && this->z < _scalar) return true;
	else return false;
}

float Vector3D::operator[](int _selector)
{
	Vector3D temp = Vector3D(this->x, this->y, this->z);
	if (_selector == 0)
	{
		return temp.x;
	}
	else if (_selector == 1)
	{
		return temp.y;
	}
	else if (_selector == 2)
	{
		return temp.z;
	}
	else return false;
	

	
}






