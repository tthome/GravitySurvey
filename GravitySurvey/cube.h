#ifndef CUBE_H
#define CUBE_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "point.h"
#include "vector3.h"

class cube
{
public:
	point* nodes[8];
	point barycenter;
	vector3 p;
	double mes;
	cube();
	void init();
	vector3 calc_g(const point& m) const;
};

#endif

