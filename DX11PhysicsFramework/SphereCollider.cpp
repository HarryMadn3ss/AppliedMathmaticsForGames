#include "SphereCollider.h"
#include "OBBCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other, CollisionManifold& out)
{
    Vector3D distance = other.GetPosition() - this->GetPosition();
    float distanceMagnitude = distance.Magnitude();

    float combindedRadii = other.GetRadius() + this->GetRadius();
    if (combindedRadii > distanceMagnitude)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SphereCollider::CollidesWith(AABBCollider& other, CollisionManifold& out)
{
    Vector3D distance = other.GetPosition() - GetPosition();

    Vector3D boxHalfExtents = other.GetHalfExtents();

    Vector3D closestPoint = GetPosition().Clamp(other.GetPosition() + boxHalfExtents, other.GetPosition() + boxHalfExtents.Inverse());

    if ((closestPoint - GetPosition()).Magnitude() < GetRadius())
    {
        return true;
    }
    else return false;
}

bool SphereCollider::CollidesWith(OBBCollider& other, CollisionManifold& out)
{
    return false;
}
