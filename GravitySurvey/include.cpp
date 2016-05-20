#include "include.h"

bool include::inside(const cube & c) const
{
	return c.barycenter.x >= x_min && c.barycenter.x <= x_max &&
		c.barycenter.y >= y_min && c.barycenter.y <= y_max &&
		c.barycenter.z >= z_min && c.barycenter.z <= z_max;
}

istream & operator>>(istream & is, include & a)
{
	is >> a.x_min >> a.x_max;
	is >> a.y_min >> a.y_max;
	is >> a.z_min >> a.z_max;
	is >> a.p.x >> a.p.y >> a.p.z;
	return is;
}

