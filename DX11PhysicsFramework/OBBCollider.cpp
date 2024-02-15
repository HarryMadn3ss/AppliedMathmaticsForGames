#include "OBBCollider.h"
#include "SphereCollider.h"

bool OBBCollider::CollidesWith(SphereCollider& other)
{
    if (other.CollidesWith(other)) return true;
    else return false;    
}

bool OBBCollider::CollidesWith(AABBCollider& other)
{
    return false;
}

bool OBBCollider::CollidesWith(OBBCollider& other)
{
    Vector3D distance = other.GetPosition() - this->GetPosition();
    float distanceMag = distance.Magnitude();

    float combindedX = other._halfExtents.x + this->_halfExtents.x;
    float combindedY = other._halfExtents.y + this->_halfExtents.y;
    float combindedZ = other._halfExtents.z + this->_halfExtents.z;

    if (combindedX > distanceMag && combindedY > distanceMag && combindedZ > distanceMag) return true;
    else return false;
}
