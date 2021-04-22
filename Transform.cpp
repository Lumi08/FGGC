#include "Transform.h"

Transform::Transform(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale)
{
	_position = position;
	_rotation = rotation;
	_scale = scale;
}

Transform::Transform()
{
	_position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	_rotation = XMFLOAT3(0.0f, 0.0f, 0.0f);
	_scale = XMFLOAT3(0.0f, 0.0f, 0.0f);
}

Transform::~Transform()
{
}
