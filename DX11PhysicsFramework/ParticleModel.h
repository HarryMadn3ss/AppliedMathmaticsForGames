#pragma once
#include "PhysicsModel.h"
class ParticleModel : public PhysicsModel
{
private:
	float _timeAlive;
	float _resetTime;

	bool _invertGravity;	

protected:
	bool _isActive = false;

public:
	ParticleModel();
	ParticleModel(Transform* transform, float mass) : PhysicsModel(transform, mass) {};
	ParticleModel(Transform* transform,  Vector3D pertubation, float resetTime, bool invertGravity);
	~ParticleModel();

	void Update(float deltaTime);
	void Activate();
	void Reset();

	void AddRelativeForce(Vector3D impactPoint, Vector3D force) override { AddForce(force); }

	float GetResetTime() { return _resetTime; }
	void SetResetTime(float i) { _resetTime = i; }
	Transform* GetTransform() { return _transform; }
	bool GetActive() { return _isActive; }
	bool GetInvertGrav() { return _invertGravity; }
};

