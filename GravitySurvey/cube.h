#ifndef CUBE_H
#define CUBE_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Point.h"
#include "Vector3.h"

class Cube
{
public:
	Point* nodes[8];
	Point barycenter;
	double volume;
	double rho;
	Cube();
	void initialize();
	Vector3 computeG(const Point& receiverPoint) const;
};

#endif // CUBE_H


