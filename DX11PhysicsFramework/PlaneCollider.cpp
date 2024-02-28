#include "PlaneCollider.h"

#include "OBBCollider.h"
#include "AABBCollider.h"
#include "SphereCollider.h"


bool PlaneCollider::CollidesWith(SphereCollider& other, CollisionManifold& out)
{
    float dist = Vector3D::DotProduct(other.GetPosition(), _normal);

    //Vector3D radiusDist = other.GetPosition() + other.GetRadius();

    Vector3D pointOnPlane = other.GetPosition() - (_normal * dist);

    //if (pointOnPlane.x > radiusDist.x || pointOnPlane.x < -radiusDist.x) return false;
    //if (pointOnPlane.y > radiusDist.y || pointOnPlane.y < -radiusDist.y) return false;
    //if (pointOnPlane.z > radiusDist.z || pointOnPlane.z < -radiusDist.z) return false;
    if (abs(dist) >= other.GetRadius()) return false;

    out.collisionNormal = _normal;

    //Vector3D pointBox = pointOnPlane.Clamp(maxPoint, minPoint);
    //Vector3D pointProj = other.GetPosition() * (Vector3D::DotProduct(pointBox, _normal)) / Vector3D::DotProduct(pointBox, pointBox);

    //Vector3D diff  = other.GetPosition() * _normal;

    //Vector3D diff  = other.GetPosition() * (Vector3D::DotProduct(other.GetPosition(), _normal)) / Vector3D::DotProduct(other.GetPosition(), other.GetPosition());
    float diff = Vector3D::DotProduct(this->GetPosition(), _normal) - (Vector3D::DotProduct(other.GetPosition(), _normal));



    out.contactPointCount = 1;
    //out.points[0].position = pointBox;
    out.points[0].penetrationDepth = diff + other.GetRadius();

    return true;
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
        
    Vector3D pointOnPlane = other.GetPosition() - (_normal * dist);

    if (pointOnPlane.x > maxPoint.x || pointOnPlane.x < minPoint.x) return false;
    if (pointOnPlane.y > maxPoint.y || pointOnPlane.y < minPoint.y) return false;
    if (pointOnPlane.z > maxPoint.z || pointOnPlane.z < minPoint.z) return false;

    out.collisionNormal = _normal;

    //Vector3D pointBox = pointOnPlane.Clamp(maxPoint, minPoint);
    //Vector3D pointProj = other.GetPosition() * (Vector3D::DotProduct(pointBox, _normal)) / Vector3D::DotProduct(pointBox, pointBox);

    //Vector3D diff  = other.GetPosition() * _normal;

    //Vector3D diff  = other.GetPosition() * (Vector3D::DotProduct(other.GetPosition(), _normal)) / Vector3D::DotProduct(other.GetPosition(), other.GetPosition());
    float diff  = Vector3D::DotProduct(this->GetPosition(), _normal) - (Vector3D::DotProduct(other.GetPosition(), _normal));
    
    

    out.contactPointCount = 1;
    //out.points[0].position = pointBox;
    out.points[0].penetrationDepth = diff + other.GetHalfExtents().y;

    return true;    
}

bool PlaneCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out)
{
    return false;
}
