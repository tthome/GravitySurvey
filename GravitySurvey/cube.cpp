#include "cube.h"

cube::cube()
{
	for (size_t i = 0; i < 8; i++)
		nodes[i] = nullptr;
	for (size_t i = 0; i < 6; i++)
		neighbors[i] = nullptr;
	volume = 0;
	num = 0;
}

void cube::init()
{
	double hx = nodes[1]->x - nodes[0]->x;
	double hy = nodes[2]->y - nodes[0]->y;
	double hz = nodes[4]->z - nodes[0]->z;
	volume = hx * hy * hz;
}

