#include "AABBCollider.h"
#include "OBBCollider.h"
#include "SphereCollider.h"

bool AABBCollider::CollidesWith(SphereCollider& other, CollisionManifold& out)
{
	if (other.CollidesWith(other, out)) return true;
	else return false;
}

bool AABBCollider::CollidesWith(AABBCollider& other, CollisionManifold& out)
{
	Vector3D distance = other.GetPosition() - this->GetPosition();
	float distanceMag = distance.Magnitude();

	float combindedRX = other._rx + this->_rx;
	float combindedRY = other._ry + this->_ry;
	float combindedRZ = other._rz + this->_rz;

	if (combindedRX > distanceMag && combindedRY > distanceMag && combindedRZ > distanceMag) return true;
	else return false;
}

bool AABBCollider::CollidesWith(OBBCollider& other, CollisionManifold& out)
{
	return false;
}
