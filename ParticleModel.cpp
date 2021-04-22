#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float speed, float acceleration)
{
	_transform = transform;
	_velocity = speed;
	_acceleration = acceleration;
}

ParticleModel::~ParticleModel()
{
}

void ParticleModel::Update(float t)
{
	//MoveConstVelocity(t);
	MoveConstAcceleration(t);
}

void ParticleModel::MoveConstVelocity(float t)
{
	XMFLOAT3 pos = _transform->GetPosition();
	pos.z += _velocity;
	_transform->SetPosition(pos);
}

void ParticleModel::MoveConstAcceleration(float t)
{
	XMFLOAT3 pos = _transform->GetPosition();
	pos.z += _velocity;
	_velocity += _acceleration;
	_transform->SetPosition(pos);
}

void ParticleModel::MoveForward()
{
	XMFLOAT3 pos = _transform->GetPosition();
	pos.z -= _velocity;
	_transform->SetPosition(pos);
}

void ParticleModel::MoveBackward()
{
	XMFLOAT3 pos = _transform->GetPosition();
	pos.z += _velocity;
	_transform->SetPosition(pos);
}

