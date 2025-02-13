#pragma once

#include "Transform.h"
#include "SphereCollider.h"
#include "OBBCollider.h"
#include "PlaneCollider.h"
#include "AABBCollider.h"

class PhysicsModel
{
private:

protected:
	XMFLOAT3X3 _ineriaTensor;
	float _angularDampening = 0.1f;
	Vector3D _angularVelocity = Vector3D();
	Vector3D _torque = Vector3D();

	Transform* _transform = nullptr;
	Vector3D _velocity = Vector3D(0, 0, 0);

	Collider* _collider = nullptr;

	Vector3D _acclerationValue = Vector3D(0, 0, 0);
	/*bool _constantAcceleration = false;*/

	bool _simulateGravity = true;
	Vector3D _netForce = Vector3D(0, 0, 0);
	float _mass = 1.0f;

	bool _simulateDrag = true;
	float _dragValue = 0;
	bool _simulateFriction= false;
	float _frictionValue = 0;
public:
	PhysicsModel();
	PhysicsModel(Transform* transform, float mass);
	virtual ~PhysicsModel() = 0;

	void Update(float deltaTime, bool invertGrav = false);
	Vector3D GetVelocity() { return _velocity; }
	void SetVelocity(Vector3D velocity) { _velocity = velocity; }	
	void SetAcclerationValue(Vector3D acceleration) { _acclerationValue = acceleration; }
	/*void SetIsAccleration(bool isAcclerating) { _constantAcceleration = isAcclerating; }*/

	float GetMass() { return _mass; }

	float GetInverseMass(){	if (_mass == 0) return 0;  return 1 / _mass; }

	void AddForce(Vector3D force) { _netForce += force; }
	Vector3D GravityForce() { return Vector3D(0, -9.81f * _mass, 0); }
	void SetGravity(bool gravity) { _simulateGravity = gravity; }
	Vector3D DragForce();
	Vector3D FrictionForce();

	bool IsCollidable() const { return _collider != nullptr; }
	Collider* GetCollider() const { return _collider; }
	void SetCollider(Collider* collider) { _collider = collider; }

	//collision reposne
	void ApplyImpulse(Vector3D impulse){ _velocity += impulse; }

	virtual void AddRelativeForce(Vector3D impactPoint, Vector3D force) = 0;

	void CalculateAngularVelocity(float deltaTime);
};

