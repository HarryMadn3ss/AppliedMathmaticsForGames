#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
private:


protected:
	
	Vector3D _minCorner, _maxCorner, _centerPoint;
	//extents
	float _dx, _dy, _dz;
	//half extents
	float _rx, _ry, _rz;

public:
	AABBCollider(Transform* Transform, Vector3D extents) : Collider(Transform) { _dx = extents.x, _dy = extents.y, _dz = extents.z, _rx = _dx/2, _ry = _dy/2, _rz = _dz/2, _centerPoint = GetPosition(); };

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;


};

