#pragma once

#include "Structures.h"

class Appearance
{
private:
	Geometry _geometry;
	Material _material;

protected:


public:
	Appearance(Geometry geometry, Material material);
	~Appearance();


	Geometry GetGeometryData() const { return _geometry; }
	//Geometry SetGeometryData(Geometry geometry){ _geometry = geometry; };

	Material GetMaterial() const { return _material; }
	//Material SetMaterial(Material material) { _material = material; }

	//draw()
};

