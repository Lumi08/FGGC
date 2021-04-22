#pragma once

#include "Transform.h"

using namespace DirectX;

class ParticleModel
{
public:
	ParticleModel(Transform* transform, float speed);
	~ParticleModel();

	void SetTransform(Transform* transform) { _transform = transform; }

	void MoveForward();
	void MoveBackward();

private:
	Transform* _transform;
	float _speed;
};

