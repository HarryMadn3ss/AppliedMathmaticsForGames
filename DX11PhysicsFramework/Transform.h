#pragma once

#include "Vector3D.h"

class Transform
{
private:
	Vector3D _position;
	Vector3D _rotation;
	Vector3D _scale;

protected:


public:
	Transform();
	~Transform();


	void SetPosiition(Vector3D position) { _position = position; }
	Vector3D GetPosition() const { return _position; }
	void SetRotation(Vector3D rotation) { _rotation = rotation; }
	Vector3D GetRotation() const { return _rotation; }
	void SetScale(Vector3D scale) { _scale = scale; }
	Vector3D GetScale() const { return _scale; }
};

