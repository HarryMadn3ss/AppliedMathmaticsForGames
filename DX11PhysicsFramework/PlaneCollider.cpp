#include "PlaneCollider.h"

#include "OBBCollider.h"
#include "AABBCollider.h"
#include "SphereCollider.h"


bool PlaneCollider::CollidesWith(SphereCollider& other, CollisionManifold& out)
{
    return false;
}

bool PlaneCollider::CollidesWith(AABBCollider& other, CollisionManifold& out)
{
    return false;
}

bool PlaneCollider::CollidesWith(OBBCollider& other, CollisionManifold& out)
{
    //float plane = Vector3D::DotProduct(_normal, Vector3D(1.0f, 0.0f, 0.0f));

    float dist = Vector3D::DotProduct(other.GetPosition(), _normal);

    Vector3D maxPoint = other.GetPosition() + other.GetHalfExtents();
    Vector3D minPoint = other.GetPosition() - other.GetHalfExtents();
        
    if (dist > maxPoint.x || dist < minPoint.x) return false;
    if (dist > maxPoint.y || dist < minPoint.y) return false;
    if (dist > maxPoint.z || dist < minPoint.z) return false;

    Vector3D diff = other.GetPosition() - _center;
    out.collisionNormal = diff.Normalize();

    Vector3D pointBox = this->GetPosition().Clamp(maxPoint, other.GetPosition() + minPoint);
    Vector3D pointProj = pointBox * (Vector3D::DotProduct(pointBox, out.collisionNormal)) / Vector3D::DotProduct(pointBox, pointBox);
    float pointDist = (pointProj - _center).Magnitude();

    out.contactPointCount = 2;
    out.points[0].position = pointBox;
    out.points[0].penetrationDepth = pointDist;

    return true;    
}

bool PlaneCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out)
{
    return false;
}
