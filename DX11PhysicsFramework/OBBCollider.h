#pragma once
#include "Collider.h"
class OBBCollider :	public Collider
{
private:
	

protected:
	Vector3D _center;
	Vector3D _halfExtents;
	Vector3D _normalAxis[3] = { Vector3D(1,0,0), Vector3D(0,1,0), Vector3D(0,0,1) };

public:
	OBBCollider(Transform* transform, Vector3D extents) : Collider(transform) { _halfExtents = extents/2, _center = GetPosition(); }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;
	virtual bool CollidesWith(OBBCollider& other) override;

	Vector3D GetHalfExtents() { return _halfExtents; }

	void SetNormals(Vector3D right, Vector3D up, Vector3D forward) { _normalAxis[0] = right, _normalAxis[1] = up, _normalAxis[2] = forward; }

};

