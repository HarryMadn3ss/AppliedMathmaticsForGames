#pragma once

#include "Transform.h"

class PhysicsModel
{
private:
	

protected:
	Transform* _transform = nullptr;
	Vector3D _velocity = Vector3D(0, 0, 0);

	Vector3D _acclerationValue = Vector3D(0, 0, 0);
	/*bool _constantAcceleration = false;*/

	bool _simulateGravity = true;
	Vector3D _netForce = Vector3D(0, 0, 0);
	float _mass = 1.0f;

	bool _simulateDrag = true;
	float _dragValue = 0;
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
	Vector3D DragForce();

};

