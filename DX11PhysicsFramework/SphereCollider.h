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

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;

	float GetRadius() const { return _radius; }
};

