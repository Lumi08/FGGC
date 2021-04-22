#include "Vector3D.h"

Vector3D::Vector3D()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D(const Vector3D& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

Vector3D Vector3D::operator+(const Vector3D& vec)
{
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D& Vector3D::operator+=(const Vector3D& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& vec)
{
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D& Vector3D::operator-=(const Vector3D& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

Vector3D Vector3D::operator*(float value)
{
	return Vector3D(x * value, y * value, z * value);
}

Vector3D& Vector3D::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3D Vector3D::operator/(float value)
{
	assert(value != 0);
	return Vector3D(x / value, y / value, z / value);
}

Vector3D& Vector3D::operator/=(float value)
{
	assert(value != 0);
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

float Vector3D::dot_product(const Vector3D& vec)
{
	return ((x * vec.x) + (y * vec.y) + (z * vec.z));
}

Vector3D Vector3D::cross_product(const Vector3D& vec)
{
	return Vector3D(y * vec.z - z * vec.y,
		z * vec.x - x * vec.z,
		x * vec.y - y * vec.x);
}

Vector3D Vector3D::normalization()
{
	float length = this->magnitude();

	return Vector3D(x / length, y / length, z / length);
}

float Vector3D::square()
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3D::distance(const Vector3D& vec)
{
	return sqrt(((vec.x - x) * (vec.x - x)) + ((vec.y - y) * (vec.y - y)) + ((vec.z - z) * (vec.z - z)));
}

float Vector3D::magnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}

float Vector3D::show_X()
{
	return x;
}

float Vector3D::show_Y()
{
	return y;
}

float Vector3D::show_Z()
{
	return z;
}

void Vector3D::disp()
{
	cout << x << " " << y << " " << z << endl;
}
