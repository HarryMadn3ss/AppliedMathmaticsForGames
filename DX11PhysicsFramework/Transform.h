#pragma once

//#include "Vector3D.h"
#include "Quaternion.h"

class Transform
{
private:
	Vector3D _position;
	//Vector3D _rotation;
	Quaternion _orientation;
	Vector3D _scale;

protected:


public:
	Transform();
	~Transform();


	void SetPosition(Vector3D position) { _position = position; }
	Vector3D GetPosition() const { return _position; }

	void SetRotation(Vector3D rotation) { _orientation = MakeQFromEulerAngles(rotation.x, rotation.y, rotation.z); }
	void SetRotation(float x, float y, float z) { _orientation = MakeQFromEulerAngles(x, y, z); }

	void SetOrientation(Quaternion orientation) { _orientation = orientation; }


	Vector3D GetRotation() const { return MakeEulerAnglesFromQ(_orientation); }
	Quaternion GetOrientation() const { return _orientation; }

	void SetScale(Vector3D scale) { _scale = scale; }
	Vector3D GetScale() const { return _scale; }
};

