#include "ParticleModel.h"





ParticleModel::ParticleModel(Transform* transform, Vector3D pertubation, float resetTime, bool invertGravity)
{
	_transform = transform;
	_resetTime = resetTime;
	_timeAlive = 0.0f;
	_invertGravity = invertGravity;
}

ParticleModel::~ParticleModel()
{
}

void ParticleModel::Update(float deltaTime)
{
	//PhysicsModel::Update(deltaTime);

	if (!_isActive)
	{
		Activate();
	}

	_timeAlive += deltaTime;
	if (_timeAlive > _resetTime)
	{
		Reset();
	}

	if (_isActive)
	{
		PhysicsModel::Update(deltaTime, _invertGravity);
	}
}

void ParticleModel::Activate()
{
	_isActive = true;
	_transform->SetPosition(Vector3D(-5.0f, 1.5f, 10.0f));
}

void ParticleModel::Reset()
{
	_isActive = false;
	_timeAlive == 0.0f;
	_transform->SetPosition(Vector3D(1000.0f, 1000.0f, 1000.0f));
}
