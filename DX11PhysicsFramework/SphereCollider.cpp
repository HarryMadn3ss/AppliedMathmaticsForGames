#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other)
{
    Vector3D distance = other.GetPosition() - this->GetPosition();
    float distanceMagnitude = distance.Magnitude(distance);

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
