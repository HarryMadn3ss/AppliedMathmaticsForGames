#pragma once
#include "PhysicsModel.h"
class ParticleModel : public PhysicsModel
{
private:
	float _timeAlive;
	float _resetTime;

	bool _invertGravity;

protected:

public:
	ParticleModel(Transform* transform, float mass) : PhysicsModel(transform, mass) {};
	ParticleModel(Transform* transform,  Vector3D pertubation, float resetTime, bool invertGravity);
	~ParticleModel();

	void Update(float deltaTime);
	void Reset();

	void AddRelativeForce(Vector3D impactPoint, Vector3D force) override { AddForce(force); }
};

