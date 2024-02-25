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

	float combindedRX = other.GetHalfExtents()[0] + this->GetHalfExtents()[0];
	float combindedRY = other.GetHalfExtents()[1] + this->GetHalfExtents()[1];
	float combindedRZ = other.GetHalfExtents()[2] + this->GetHalfExtents()[2];

	if (combindedRX > distanceMag && combindedRY > distanceMag && combindedRZ > distanceMag) return true;
	else return false;
}

bool AABBCollider::CollidesWith(OBBCollider& other, CollisionManifold& out)
{
	if (other.CollidesWith(other, out)) return true;
	return false;
}
