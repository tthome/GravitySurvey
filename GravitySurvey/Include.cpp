#include "Include.h"

bool Include::isInside(const Cube& cube) const
{
	bool isInsideX = cube.barycenter.x >= xMin && cube.barycenter.x <= xMax;
	bool isInsideY = cube.barycenter.y >= yMin && cube.barycenter.y <= yMax;
	bool isInsideZ = cube.barycenter.z >= zMin && cube.barycenter.z <= zMax;
	return isInsideX && isInsideY && isInsideZ;
}

istream& operator>>(istream& is, Include& include)
{
	is >> include.xMin >> include.xMax;
	is >> include.yMin >> include.yMax;
	is >> include.zMin >> include.zMax;
	is >> include.rho;
	return is;
}

