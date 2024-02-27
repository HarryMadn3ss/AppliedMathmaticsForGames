#include "SphereCollider.h"
#include "OBBCollider.h"
#include "PlaneCollider.h"

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
    /*Vector3D distance = other.GetPosition() - GetPosition();*/

    Vector3D diff = other.GetPosition() - this->GetPosition();    
    out.collisionNormal = diff.Normalize();    

    Vector3D boxHalfExtents = other.GetHalfExtents();

    Vector3D closestPoint = GetPosition().Clamp(other.GetPosition() + boxHalfExtents, other.GetPosition() + boxHalfExtents.Inverse());

    Vector3D obbPos = other.GetPosition();

    Vector3D pointAProj = closestPoint * (Vector3D::DotProduct(closestPoint, out.collisionNormal)) / Vector3D::DotProduct(closestPoint, closestPoint);
    Vector3D pointBProj = obbPos * (Vector3D::DotProduct(obbPos, out.collisionNormal)) / Vector3D::DotProduct(obbPos, obbPos);

    float pointDist = (pointAProj - pointBProj).Magnitude();


    //out.collisionNormal.Normalize();
    out.contactPointCount = 2;
    out.points[0].position = closestPoint;
    out.points[0].penetrationDepth = pointDist;

    if ((closestPoint - GetPosition()).Magnitude() < GetRadius())
    {
        return true;
    }
    else return false;
}

bool SphereCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out)
{
    return false;
}
