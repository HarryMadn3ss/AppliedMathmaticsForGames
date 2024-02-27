#pragma once
#include "Collider.h"
class PlaneCollider : public Collider
{
private:
	Vector3D _center = Vector3D();
	Vector3D _normal = Vector3D(0.0f, 1.0f, 0.0f);
protected:

public:
	PlaneCollider(Transform* transform) : Collider(transform) { ; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(OBBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(PlaneCollider& other, CollisionManifold& out) override;
};

