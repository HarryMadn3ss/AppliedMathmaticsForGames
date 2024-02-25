#include "ParticleModel.h"





ParticleModel::ParticleModel(Transform* transform, Vector3D pertubation, float resetTime, bool invertGravity)
{
	_transform = transform;
	_resetTime = resetTime;
	_invertGravity = invertGravity;
}

ParticleModel::~ParticleModel()
{
}

void ParticleModel::Update(float deltaTime)
{
	//PhysicsModel::Update(deltaTime);

	/*_timeAlive += deltaTime;
	if (_timeAlive > _resetTime)
	{
		Reset();
	}*/

	PhysicsModel::Update(deltaTime);
}

void ParticleModel::Reset()
{
}
