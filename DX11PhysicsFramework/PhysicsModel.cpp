#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform, float mass)
{
	_transform = transform;
	_mass = mass;
}

PhysicsModel::~PhysicsModel()
{
	//_transform = nullptr;
}

void PhysicsModel::Update(float deltaTime)
{
	Vector3D position = _transform->GetPosition();

	if (_simulateGravity)
	{
		_netForce += GravityForce();
	}

	_acclerationValue += _netForce / _mass;
	if (_netForce.z == -1)
	{
		int i = 0;
	}

	//if (_constantAcceleration)
	{
		_acclerationValue = _acclerationValue * deltaTime;	
		_velocity = _velocity + _acclerationValue;
		position += _velocity * deltaTime;
	}
	/*else
	{
		position += _velocity * deltaTime;
	}*/


	_transform->SetPosition(position);

	_acclerationValue = Vector3D(0, 0, 0);
	_netForce = Vector3D(0, 0, 0);
}

Vector3D PhysicsModel::DragForce()
{
	Vector3D velCopy = Vector3D(-_velocity.x, -_velocity.y, -_velocity.z);
	velCopy = velCopy.Normalize(velCopy);

	_dragValue = 0.5 * 1.293 * 1.05 * 1 * velCopy.Magnitude(velCopy * velCopy);
}
