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
	Cube* neighbors[6];

	double volume = 0;
	double rho = 0;
	int id = 0;

	Cube();
	void initialize();
	Vector3 computeG(const Point& receiverPoint) const;
	bool isNeighbor(const Cube& cube) const;
};

#endif // CUBE_H


