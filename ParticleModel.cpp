#include "ParticleModel.h"
#include "Vector3D.h"
#include "Debug.h"

ParticleModel::ParticleModel(Transform* transform, bool useConstAccel, XMFLOAT3 speed, XMFLOAT3 acceleration)
{
	_transform = transform;
	_currentVelocity = speed;
	_initialVelocity = speed;
	_acceleration = acceleration;
	_accelerating = useConstAccel;
}

ParticleModel::~ParticleModel()
{
	delete _transform;
}

void ParticleModel::Update(float t)
{
	if(_accelerating)
	{
		//MoveConstVelocity(t);
		MoveConstAcceleration(t);
	}
}

void ParticleModel::MoveConstVelocity(float t)
{
	Vector3D pos = { _transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z };
	Vector3D vel = { _currentVelocity.x, _currentVelocity.y, _currentVelocity.z };
	pos += vel;
	_transform->SetPosition(XMFLOAT3(pos.x, pos.y, pos.z));
}

void ParticleModel::MoveConstAcceleration(float t)
{
	MoveConstVelocity(t);

	_currentVelocity.x += _acceleration.x;
	_currentVelocity.y += _acceleration.y;
	_currentVelocity.z += _acceleration.z;

	Debug::PrintDebugText(std::to_string(_acceleration.x) + " " + std::to_string(_acceleration.y) + " " + std::to_string(_acceleration.z));
}

void ParticleModel::MoveForward()
{
	Vector3D pos = { _transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z };
	Vector3D vel = { _currentVelocity.x, _currentVelocity.y, _currentVelocity.z };
	pos -= vel;
	_transform->SetPosition(XMFLOAT3(pos.x, pos.y, pos.z));
}

void ParticleModel::MoveBackward()
{
	Vector3D pos = { _transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z };
	Vector3D vel = { _currentVelocity.x, _currentVelocity.y, _currentVelocity.z };
	pos += vel;
	_transform->SetPosition(XMFLOAT3(pos.x, pos.y, pos.z));
}

