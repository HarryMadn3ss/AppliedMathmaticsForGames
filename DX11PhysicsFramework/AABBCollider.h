#pragma once
#include "Collider.h"
//#include "SphereCollider.h"

class AABBCollider : public Collider
{
private:


protected:
	
	Vector3D _minCorner, _maxCorner, _centerPoint;
	//extents
	float _dx, _dy, _dz;
	//half extents
	Vector3D _halfExtents;
	Vector3D _normalAxis[3] = { Vector3D(1,0,0), Vector3D(0,1,0), Vector3D(0,0,1) };

public:
	AABBCollider(Transform* Transform, Vector3D extents) : Collider(Transform) { _dx = extents.x, _dy = extents.y, _dz = extents.z, _halfExtents = extents/2, _centerPoint = GetPosition(); };

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(OBBCollider& other, CollisionManifold& out) override;
	bool CollidesWith(PlaneCollider& other, CollisionManifold& out) override;


	Vector3D GetHalfExtents() { return _halfExtents; }
	Vector3D GetNormalAxis(int i) { return _normalAxis[i]; }

};

