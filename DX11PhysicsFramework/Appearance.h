#pragma once

#include "Structures.h"

class Appearance
{
private:
	Geometry _geometry;
	Material _material;

protected:


public:
	Geometry GetGeometryData() const { return _geometry; }
	Material GetMaterial() const { return _material; }
};

