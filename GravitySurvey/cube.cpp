#include "cube.h"

cube::cube()
{
	for (size_t i = 0; i < 8; i++)
		nodes[i] = nullptr;
	mes = 0;
}

void cube::init()
{
	double hx = nodes[1]->x - nodes[0]->x,
		hy = nodes[2]->y - nodes[0]->y,
		hz = nodes[4]->z - nodes[0]->z;
	mes = hx * hy * hz;
	barycenter = point(nodes[0]->x + hx / 2.0, nodes[0]->y + hy / 2.0, nodes[0]->z + hz / 2.0);
}

vector3 cube::calc_g(const point & m) const
{
	double dx = m.x - barycenter.x, dy = m.y - barycenter.y, dz = m.z - barycenter.z;
	double r = sqrt(dx * dx + dy * dy + dz * dz);
	double b = mes / (4 * M_PI * pow(r, 3));
	double gx = b * dx,
		gy = b * dy,
		gz = b * dz;
	return vector3(gx, gy, gz);
}

