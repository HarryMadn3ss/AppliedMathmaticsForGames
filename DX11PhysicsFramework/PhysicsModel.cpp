#include "PhysicsModel.h"
#include <cmath>

PhysicsModel::PhysicsModel()
{
}

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


	if (position.y > 1)
	{
		_simulateGravity = true;
		_simulateFriction = false;
	}
	else
	{
		_simulateGravity = false;
		_simulateFriction = true;
	}

	if (_simulateGravity)
	{
		_netForce += GravityForce();
	}	

	if (_simulateFriction)
	{
		_netForce += FrictionForce();
	}

	if (_simulateDrag)
	{
		_netForce += DragForce();
	}	
	

	_acclerationValue += _netForce / _mass;
	_velocity = _velocity + _acclerationValue * deltaTime;	
	position += _velocity * deltaTime;
	
	_transform->SetPosition(position);

	_acclerationValue = Vector3D(0, 0, 0);
	_netForce = Vector3D(0, 0, 0);	
}

Vector3D PhysicsModel::DragForce()
{
	Vector3D velCopy = GetVelocity();	
	

	float magnitude = velCopy.Magnitude();

	_dragValue = 0.5 * (magnitude * magnitude) * 1.293 * 1.05 * 1;

	if (_dragValue > _mass * 9.81)
	{
		_dragValue = _mass * 9.81;
	}	

	Vector3D finalDrag = velCopy.Normalize() * -_dragValue;
		
	return finalDrag;
		
}

Vector3D PhysicsModel::FrictionForce()
{
	_frictionValue = 0.42 * _mass  * 9.81 ;

	Vector3D velCopy = GetVelocity();
	float mag = velCopy.Magnitude();
	
	Vector3D finalFriction = velCopy.Normalize() * -_frictionValue;

	//if (finalFriction > (velCopy * -1))
	//{
	//	//limit
	//	return velCopy;
	//}
	//else if (finalFriction < velCopy)
	/*{
		return velCopy * -1;
	}*/
	if (velCopy == Vector3D(0, 0, 0) || mag < 0.1f)
	{
		return velCopy * -1;
	}

	return finalFriction;
}
