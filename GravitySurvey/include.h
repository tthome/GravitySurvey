#ifndef INCLUDE_H
#define INCLUDE_H

#include "vector3.h"
#include "cube.h"

#include <istream>

using namespace std;

class include
{
public:
	double x_min, x_max;
	double y_min, y_max;
	double z_min, z_max;
	vector3 p;
	bool inside(const cube& c) const;
	friend istream& operator >>(istream& is, include& a);
};

#endif

