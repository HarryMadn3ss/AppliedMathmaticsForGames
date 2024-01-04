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


	//cros and dot product
	float DotProduct(Vector3D _vectorOne, Vector3D _vectorTwo);
	Vector3D CrossProduct(Vector3D _vectorOne, Vector3D _vectorTwo);

	//magnitude andnomalization
};

