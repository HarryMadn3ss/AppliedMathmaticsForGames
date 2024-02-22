#pragma once

#include "Transform.h"

class SphereCollider;
class AABBCollider;
class OBBCollider;

class Collider 
{
private:


protected:
	Transform* _transform;

public:
	Collider();
	Collider(Transform* transform) { _transform = transform; }
	

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) = 0;
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) = 0;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) = 0;
	virtual bool CollidesWith(OBBCollider& other, CollisionManifold& out) = 0;

	Vector3D GetPosition() const { return _transform->GetPosition(); }

};

