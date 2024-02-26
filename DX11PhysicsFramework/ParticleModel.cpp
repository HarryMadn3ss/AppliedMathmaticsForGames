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
	
}

void ParticleModel::Activate()
{
	
}

void ParticleModel::Reset()
{
	
}
