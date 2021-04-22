#include "GameObject.h"
#include "Debug.h"

GameObject::GameObject(string type, Transform* transform, ParticleModel* particleModel, Apperance* apperance)
{
	_type = type;
	_transform = transform;
	_particleModel = particleModel;
	_apperance = apperance;

	_parent = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_particleModel->SetTransform(_transform);
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_transform->GetScale().x, _transform->GetScale().y, _transform->GetScale().z);
	XMMATRIX rotation = XMMatrixRotationX(_transform->GetRotation().x) * XMMatrixRotationY(_transform->GetRotation().y) * XMMatrixRotationZ(_transform->GetRotation().z);
	XMMATRIX translation = XMMatrixTranslation(_transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z);

	if (_type == "Cube ")
	{
		Debug::PrintDebugText(std::to_string(t));
	}

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	Geometry geometry = _apperance->GetGeometryData();

	// Set vertex and index buffers
	pImmediateContext->IASetVertexBuffers(0, 1, &geometry.vertexBuffer, &geometry.vertexBufferStride, &geometry.vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(geometry.numberOfIndices, 0, 0);
}
