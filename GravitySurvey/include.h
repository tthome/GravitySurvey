#ifndef INCLUDE_H
#define INCLUDE_H

#include "Cube.h"

#include <istream>

using namespace std;

class Include
{
public:

	double xMin, xMax;
	double yMin, yMax;
	double zMin, zMax;

	double rho;

	bool isInside(const Cube& cube) const;

	friend istream& operator >>(istream& is, Include& include);
};

#endif // INCLUDE_H


