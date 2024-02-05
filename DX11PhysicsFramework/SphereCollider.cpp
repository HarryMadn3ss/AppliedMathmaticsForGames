#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other)
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

bool SphereCollider::CollidesWith(AABBCollider& other)
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
