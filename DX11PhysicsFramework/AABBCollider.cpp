#include "AABBCollider.h"



AABBCollider::AABBCollider(Transform* Transform, Vector3D extents)
{
	//full extents
	_dx = extents.x, _dy = extents.y, _dz = extents.z;
	//half extents
	_rx = _dx / 2, _ry = _dy / 2, _rz = _dz / 2;
	//centre
	_centerPoint = GetPosition();
}

bool AABBCollider::CollidesWith(SphereCollider& other)
{
	return false;
}

bool AABBCollider::CollidesWith(AABBCollider& other)
{
	Vector3D distance = other.GetPosition() - this->GetPosition();
	float distanceMag = distance.Magnitude();

	float combindedRX = other._rx + this->_rx;
	float combindedRY = other._ry + this->_ry;
	float combindedRZ = other._rz + this->_rz;

	if (combindedRX > distanceMag && combindedRY > distanceMag && combindedRZ > distanceMag) return true;
	else return false;
}
