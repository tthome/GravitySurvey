#include "Cube.h"

#include <cmath>

Cube::Cube()
{
	for (int i = 0; i < 8; i++)
	{
		nodes[i] = nullptr;
	}
	volume = 0;
}

void Cube::initialize()
{
	double hx = nodes[1]->x - nodes[0]->x;
	double hy = nodes[2]->y - nodes[0]->y;
	double hz = nodes[4]->z - nodes[0]->z;
	volume = hx * hy * hz;
	barycenter = Point(nodes[0]->x + hx / 2.0, nodes[0]->y + hy / 2.0, nodes[0]->z + hz / 2.0);
}

Vector3 Cube::computeG(const Point& receiverPoint) const
{
	double dx = receiverPoint.x - barycenter.x;
	double dy = receiverPoint.y - barycenter.y;
	double dz = receiverPoint.z - barycenter.z;
	double r = sqrt(dx * dx + dy * dy + dz * dz);
	double b = volume / (4 * M_PI * pow(r, 3));
	double gx = b * dx;
	double gy = b * dy;
	double gz = b * dz;
	return Vector3(gx, gy, gz);
}

