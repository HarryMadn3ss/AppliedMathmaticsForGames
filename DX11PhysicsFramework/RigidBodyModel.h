#pragma once
#include "PhysicsModel.h"

class RigidBodyModel : public PhysicsModel
{
private:	
	Transform* _transform;
	
	
protected:


public:
	RigidBodyModel(Transform* transform, float mass) : PhysicsModel(transform, mass) 
	{
		_transform = transform;

		Vector3D pos = _transform->GetPosition();
	};

	void Update(float deltaTime);

	void AddRelativeForce(Vector3D impactPoint, Vector3D force) override;
};

