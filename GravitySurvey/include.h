#ifndef INCLUDE_H
#define INCLUDE_H

#include "Vector3.h"
#include "Cube.h"

#include <istream>

using namespace std;

class Include
{
public:
	double xMin, xMax;
	double yMin, yMax;
	double zMin, zMax;
	Vector3 rho;
	bool isInside(const Cube& cube) const;
	friend istream& operator >>(istream& is, Include& include);
};

#endif // INCLUDE_H


