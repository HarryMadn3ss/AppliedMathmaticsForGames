#pragma once

#include <math.h>
#include <cmath>

class Vector3D
{
private:


protected:


public:
	float x = 0, y = 0, z = 0;


	Vector3D();
	~Vector3D();

	//overrides
	Vector3D(float _x, float _y, float _z);

	Vector3D Zero();

	//cros and dot product
	static float DotProduct(Vector3D _vectorOne, Vector3D _vectorTwo);
	static Vector3D CrossProduct(Vector3D _vectorOne, Vector3D _vectorTwo);

	//magnitude and nomalization
	float Magnitude();
	Vector3D Normalize();

	//other
	Vector3D Clamp(Vector3D max, Vector3D min);
	Vector3D Inverse();
	static char FindAxis(Vector3D posA, Vector3D posB);

	//overloading opperators
	//addition
	Vector3D operator+(Vector3D _vector);
	Vector3D operator+(float _scalar);
	//sub
	Vector3D operator-(Vector3D _vector);
	//multiplcation
	Vector3D operator*(Vector3D _vector);
	Vector3D operator*(float _num);
	//copy/equals
	void operator=(Vector3D _vector);
	bool operator==(Vector3D _vector);
	bool operator==(float _scalar);
	void operator+=(Vector3D _vector);
	void operator+=(float _scalar);
	void operator*=(float _scalar);
	//division
	/*Vector3D operator/(Vector3D _vector);*/
	Vector3D operator/(float _num);

	bool operator!=(Vector3D _vector);
	bool operator>(Vector3D _vector);
	bool operator>(float _scalar);
	bool operator<(Vector3D _vector);
	bool operator<(float _scalar);
	float operator[](int _selector);
};

