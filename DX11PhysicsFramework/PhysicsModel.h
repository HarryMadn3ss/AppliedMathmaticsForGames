#pragma once

#include "Transform.h"

class PhysicsModel
{
private:
	

protected:
	Transform* _transform;
	Vector3D _velocity;	

	Vector3D _acclerationValue;
	/*bool _constantAcceleration = false;*/

	bool _simulateGravity = true;
	Vector3D _netForce;
	float _mass = 1.0f;
public:
	PhysicsModel(Transform* transform, float mass);
	virtual ~PhysicsModel() = 0;

	void Update(float deltaTime);
	Vector3D GetVelocity() { return _velocity; }
	void SetVelocity(Vector3D velocity) { _velocity = velocity; }
	void SetAcclerationValue(Vector3D acceleration) { _acclerationValue = acceleration; }
	/*void SetIsAccleration(bool isAcclerating) { _constantAcceleration = isAcclerating; }*/

	void AddForce(Vector3D force) { _netForce += force; }
	Vector3D GravityForce() { return Vector3D(0, -9.81 * _mass, 0); }

};

