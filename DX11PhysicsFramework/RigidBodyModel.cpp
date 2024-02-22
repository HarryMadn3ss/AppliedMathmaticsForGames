#include "RigidBodyModel.h"


void RigidBodyModel::Update(float deltaTime)
{
	PhysicsModel::Update(deltaTime);

}

void RigidBodyModel::AddRelativeForce(Vector3D impactPoint, Vector3D force)
{	
	_torque = Vector3D::CrossProduct(impactPoint, force);	
	//AddForce(_torque);	
}


