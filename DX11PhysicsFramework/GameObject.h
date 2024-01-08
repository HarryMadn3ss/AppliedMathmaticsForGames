#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>

#include "DebugClass.h"
#include "Vector3D.h"
#include "Transform.h"
#include "Appearance.h"

using namespace DirectX;
using namespace std;



class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject * parent) { _parent = parent; }

	//// Setters and Getters for position/rotation/scale
	//void SetPosition(Vector3D position) { _position = position; }
	//void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	//Vector3D GetPosition() const { return _position; }

	//void SetScale(Vector3D scale) { _scale = scale; }
	//void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	//Vector3D GetScale() const { return _scale; }

	//void SetRotation(Vector3D rotation) { _rotation = rotation; }
	//void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	//Vector3D GetRotation() const { return _rotation; }


	// Rendering information
	
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

	void SetTextureRV(ID3D11ShaderResourceView * textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* const* GetTextureRV() { return &_textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	void Update(float dt);
	void Move(Vector3D direction);
	void Draw(ID3D11DeviceContext * pImmediateContext);

	Transform* _transform;
	Appearance* _appearance;

private:
	GameObject* _parent = nullptr;

	Vector3D _position;
	Vector3D _rotation;
	Vector3D _scale;

	string _type;
	XMFLOAT4X4 _world;

	

	ID3D11ShaderResourceView* _textureRV = nullptr;

};

