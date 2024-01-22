#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance ) : _appearance(appearance), _type(type)
{
	_parent = nullptr;

	_textureRV = nullptr;

	
	

	_position = Vector3D(0,0,0);
	_rotation = Vector3D(0, 0, 0);
	_scale = Vector3D(0, 0, 0);
}

GameObject::~GameObject()
{
	_parent = nullptr;
	_textureRV = nullptr;
	

	//delete _physicsModel;
	//if (_physicsModel) delete _physicsModel;
	delete _appearance;
	delete _transform;
	_physicsModel = nullptr;	
	_appearance = nullptr;
	_transform = nullptr;
}

void GameObject::Update(float dt)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_transform->GetScale().x, _transform->GetScale().y, _transform->GetScale().z);
	XMMATRIX rotation = XMMatrixRotationX(_transform->GetRotation().x) * XMMatrixRotationY(_transform->GetRotation().y) * XMMatrixRotationZ(_transform->GetRotation().z);
	XMMATRIX translation = XMMatrixTranslation(_transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
		
	if (_physicsModel != nullptr)
	{
		_physicsModel->Update(dt);
	}

	//DebugClass::Instance()->PrintDebugInt(5);
}

void GameObject::MoveForward()
{
	_physicsModel->AddForce(Vector3D(0, 0, -5));
}

void GameObject::MoveLeft()
{
	_physicsModel->AddForce(Vector3D(-5, 0, 0));
}

void GameObject::MoveRight()
{
	_physicsModel->AddForce(Vector3D(5, 0, 0));
}

void GameObject::MoveBackward()
{
	_physicsModel->AddForce(Vector3D(0, 0, 5));
}

//void GameObject::Move(Vector3D direction)
//{
//	/*float x, y, z;
//
//	x = _transform->GetPosition().x + direction.x;
//	y = _transform->GetPosition().y + direction.y;
//	z = _transform->GetPosition().z + direction.z;
//	_transform->SetPosition(Vector3D(x, y, z));*/
//}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	Geometry _geometry = _appearance->GetGeometryData();

	pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(_appearance->GetGeometryData().indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(_appearance->GetGeometryData().numberOfIndices, 0, 0);
}
