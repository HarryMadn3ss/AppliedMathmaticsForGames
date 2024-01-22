#pragma once
#include "PhysicsModel.h"

class RigidBodyModel : public PhysicsModel
{
private:


protected:


public:
	RigidBodyModel(Transform* transform, float mass) : PhysicsModel(transform, mass) {};

};

