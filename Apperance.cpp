#include "Apperance.h"

Apperance::Apperance(Geometry geometry, Material material)
{
	_geometry = geometry;
	_material = material;
	_textureRV = nullptr;
}

Apperance::~Apperance()
{
}
