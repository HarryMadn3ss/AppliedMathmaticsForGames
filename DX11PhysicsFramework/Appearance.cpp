#include "Appearance.h"

Appearance::Appearance(Geometry geometry, Material material)
{
	_geometry = geometry;
	_material = material;
}

Appearance::~Appearance()
{
	_geometry.indexBuffer = nullptr;
	_geometry.vertexBuffer = nullptr;
}
