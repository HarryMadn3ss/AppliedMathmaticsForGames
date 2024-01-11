#pragma once

#include "Transform.h"

class PhysicsModel
{
private:


protected:
	Transform* _transform;
	Vector3D _velocity;

public:
	PhysicsModel(Transform* transform);
	~PhysicsModel();

	void Update(float deltaTime);

	Vector3D GetVelocity() { return _velocity; }
	void SetVelocity(Vector3D velocity) { _velocity = velocity; }

};

