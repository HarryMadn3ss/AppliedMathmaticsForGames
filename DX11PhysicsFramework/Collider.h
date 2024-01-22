#pragma once

#include "Transform.h"

class SphereCollider;

class Collider 
{
private:


protected:
	Transform* _transform;

public:
	Collider();
	Collider(Transform* transform) { _transform = transform; }
	

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;

	Vector3D GetPosition() const { return _transform->GetPosition(); }

};

