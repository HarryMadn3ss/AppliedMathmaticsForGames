#pragma once
#include "PhysicsModel.h"
class ParticleModel : public PhysicsModel
{
private:

protected:

public:
	ParticleModel(Transform* transform, float mass);
	~ParticleModel();
};

