#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{
	_transform = transform;
}

PhysicsModel::~PhysicsModel()
{
	//_transform = nullptr;
}

void PhysicsModel::Update(float deltaTime)
{
	Vector3D position = _transform->GetPosition();
	position += _velocity * deltaTime;
	_transform->SetPosition(position);
}
