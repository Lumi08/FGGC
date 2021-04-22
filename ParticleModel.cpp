#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float speed)
{
	_transform = transform;
	_speed = speed;
}

ParticleModel::~ParticleModel()
{
}

void ParticleModel::MoveForward()
{
	XMFLOAT3 pos = _transform->GetPosition();
	pos.z -= _speed;
	_transform->SetPosition(pos);
}

void ParticleModel::MoveBackward()
{
	XMFLOAT3 pos = _transform->GetPosition();
	pos.z += _speed;
	_transform->SetPosition(pos);
}

