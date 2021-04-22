#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>

#include "Transform.h"
#include "ParticleModel.h"
#include "Apperance.h"

using namespace DirectX;
using namespace std;



class GameObject
{
public:
	GameObject(string type, Transform* transform, ParticleModel* particleModel, Apperance* apperance);
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	Transform* GetTransform() { return _transform; }
	ParticleModel* GetParticleModel() { return _particleModel; }
	Apperance* GetApperance() { return _apperance; }

	string GetType() const { return _type; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }
	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

private:
	Transform * _transform;
	ParticleModel* _particleModel;
	Apperance* _apperance;

	string _type;

	XMFLOAT4X4 _world;
	GameObject * _parent;
	ID3D11ShaderResourceView* _textureRV;
};

