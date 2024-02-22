#pragma once
#include "Collider.h"
#include "AABBCollider.h"


class SphereCollider :  public Collider
{
private:
	float _radius = 1.0f;

protected:


public:
	SphereCollider(Transform* transform, float radius) : Collider(transform) { _radius = radius; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(OBBCollider& other, CollisionManifold& out) override;

	float GetRadius() const { return _radius; }
};

