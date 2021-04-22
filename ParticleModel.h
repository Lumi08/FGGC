#pragma once

#include "Transform.h"

using namespace DirectX;

class ParticleModel
{
public:
	ParticleModel(Transform* transform, float speed, float acceleration);
	~ParticleModel();

	void Update(float t);

	void MoveConstVelocity(float t);
	void MoveConstAcceleration(float t);

	void MoveForward();
	void MoveBackward();
	
	void SetTransform(Transform* transform) { _transform = transform; }

	float GetVelocity() { return _velocity; }
	void SetVelocity(float velocity) { _velocity = velocity; }

	float GetAcceleration() { return _velocity; }
	void SetAcceleration(float acceleration) { _velocity = acceleration; }

private:
	Transform* _transform;
	float _velocity;
	float _acceleration;
};

