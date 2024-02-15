#pragma once
#include "Collider.h"
class OBBCollider :	public Collider
{
private:
	

protected:
	Vector3D _center;
	Vector3D _halfExtents;
	Vector3D _up, _forward;
public:
	OBBCollider(Transform* transform, Vector3D extents) : Collider(transform) { _halfExtents = extents, _center = GetPosition(); }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;
	virtual bool CollidesWith(OBBCollider& other) override;
};

