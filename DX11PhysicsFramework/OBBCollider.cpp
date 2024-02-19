#include "OBBCollider.h"
#include "AABBCollider.h"
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
    float boxOneRadius, boxTwoRadius;
    XMFLOAT3X3 rotationMatrix, absRotationMatrix;

    // compoute rotation expressing b in a's corrd frame
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rotationMatrix.m[i][j] = Vector3D::DotProduct(this->_normalAxis[i], other._normalAxis[j]);
        }
    }

        //compute translation vewctor 
        Vector3D transVec = this->GetPosition() - other.GetPosition();
        //brimng into box ones coord space
        transVec = Vector3D(Vector3D::DotProduct(transVec, this->_normalAxis[0]), Vector3D::DotProduct(transVec, this->_normalAxis[1]), Vector3D::DotProduct(transVec, this->_normalAxis[2]));

        //compute common sub expressions
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                absRotationMatrix.m[i][j] = abs(rotationMatrix.m[i][j]) + 0.00000000001;
            }
        }
        
        //TEST AXES L = a0, a1, a2
        for (int i = 0; i < 3; i++)
        {
            boxOneRadius = this->_halfExtents[i];
            boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[i][0] + other._halfExtents[1] * absRotationMatrix.m[i][1] + other._halfExtents[2] * absRotationMatrix.m[i][2];
            float absValue = abs(transVec[i]);
            if (absValue > boxOneRadius + boxTwoRadius) return false;
        }

        //axes l = b0, b1, b2
        for (int i = 0; i < 3; i++)
        {
            boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[0][i] + this->_halfExtents[1] * absRotationMatrix.m[1][i] + this->_halfExtents[2] * absRotationMatrix.m[2][i];
            boxTwoRadius = other._halfExtents[i];
            if (abs(transVec[0] * rotationMatrix.m[0][i] + transVec[1] * rotationMatrix.m[1][i] + transVec[2] * rotationMatrix.m[2][i]) > boxOneRadius + boxTwoRadius) return false;
        }

        //test l = a0 x b0
        boxOneRadius = this->_halfExtents[1] * absRotationMatrix.m[2][0] + this->_halfExtents[2] * absRotationMatrix.m[1][0];
        boxTwoRadius = other._halfExtents[1] * absRotationMatrix.m[0][2] + other._halfExtents[2] * absRotationMatrix.m[0][1];
        if (abs(transVec[2] * rotationMatrix.m[1][0] - transVec[1] * rotationMatrix.m[2][0]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a0 x b1
        boxOneRadius = this->_halfExtents[1] * absRotationMatrix.m[2][1] + this->_halfExtents[2] * absRotationMatrix.m[1][1];
        boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[0][2] + other._halfExtents[2] * absRotationMatrix.m[0][0];
        if (abs(transVec[2] * rotationMatrix.m[1][1] - transVec[1] * rotationMatrix.m[2][1]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a0 x b2
        boxOneRadius = this->_halfExtents[1] * absRotationMatrix.m[2][2] + this->_halfExtents[2] * absRotationMatrix.m[1][2];
        boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[0][1] + other._halfExtents[1] * absRotationMatrix.m[0][0];
        if (abs(transVec[2] * rotationMatrix.m[1][2] - transVec[1] * rotationMatrix.m[2][2]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a1 x b0
        boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[2][0] + this->_halfExtents[2] * absRotationMatrix.m[0][0];
        boxTwoRadius = other._halfExtents[1] * absRotationMatrix.m[1][2] + other._halfExtents[2] * absRotationMatrix.m[1][1];
        if (abs(transVec[0] * rotationMatrix.m[2][0] - transVec[2] * rotationMatrix.m[0][0]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a1 xb1
        boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[2][1] + this->_halfExtents[2] * absRotationMatrix.m[0][1];
        boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[1][2] + other._halfExtents[2] * absRotationMatrix.m[1][0];
        if (abs(transVec[0] * rotationMatrix.m[2][1] - transVec[2] * rotationMatrix.m[0][1]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a1 x b2
        boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[2][2] + this->_halfExtents[2] * absRotationMatrix.m[0][2];
        boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[1][1] + other._halfExtents[1] * absRotationMatrix.m[1][0];
        if (abs(transVec[0] * rotationMatrix.m[2][2] - transVec[2] * rotationMatrix.m[0][2]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a2 x b0
        boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[1][0] + this->_halfExtents[1] * absRotationMatrix.m[0][0];
        boxTwoRadius = other._halfExtents[1] * absRotationMatrix.m[2][2] + other._halfExtents[2] * absRotationMatrix.m[2][1];
        if (abs(transVec[1] * rotationMatrix.m[0][0] - transVec[0] * rotationMatrix.m[1][0]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a2 xb1
        boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[1][1] + this->_halfExtents[1] * absRotationMatrix.m[0][1];
        boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[2][2] + other._halfExtents[2] * absRotationMatrix.m[2][0];
        if (abs(transVec[1] * rotationMatrix.m[0][1] - transVec[0] * rotationMatrix.m[1][1]) > boxOneRadius + boxTwoRadius) return false;

        //test l = a2 x b2
        boxOneRadius = this->_halfExtents[0] * absRotationMatrix.m[1][2] + this->_halfExtents[1] * absRotationMatrix.m[0][2];
        boxTwoRadius = other._halfExtents[0] * absRotationMatrix.m[2][1] + other._halfExtents[1] * absRotationMatrix.m[2][0];
        if (abs(transVec[1] * rotationMatrix.m[0][2] - transVec[0] * rotationMatrix.m[1][2]) > boxOneRadius + boxTwoRadius) return false;

        //if no axis is found
        return true;    
}
