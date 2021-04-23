#pragma once

#include "Transform.h"

using namespace DirectX;



class ParticleModel
{
public:
	ParticleModel(Transform* transform, bool useConstAccel, XMFLOAT3 speed, XMFLOAT3 acceleration);
	~ParticleModel();

	void Update(float t);

	void MoveConstVelocity(float t);
	void MoveConstAcceleration(float t);

	void MoveForward();
	void MoveBackward();

	void ResetVelocity() { _currentVelocity = _initialVelocity; }
	
	void SetTransform(Transform* transform) { _transform = transform; }

	XMFLOAT3 GetVelocity() { return _currentVelocity; }
	void SetVelocity(XMFLOAT3 velocity) { _currentVelocity = velocity; }

	XMFLOAT3 GetAcceleration() { return _acceleration; }
	void SetAcceleration(XMFLOAT3 acceleration) { _acceleration = acceleration; }

	bool IsAccelerating() { return _accelerating; }
	void SetAccelerating(bool state) { _accelerating = state; }

	XMFLOAT2 GetNetForce() { return _netForce; }
	void SetNetForce(XMFLOAT2 netForce) { _netForce = netForce; }

	float GetMass() { return _mass; }
	void SetMass(float mass) { _mass = mass; }

private:

	Transform* _transform;
	XMFLOAT3 _initialVelocity;
	XMFLOAT3 _currentVelocity;

	XMFLOAT3 _acceleration;
	bool _accelerating;

	XMFLOAT2 _netForce;
	float _mass;

};

