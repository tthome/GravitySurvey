#include "include.h"

bool include::inside(const cube & p) const
{
	return p.barycenter.x >= x_min && p.barycenter.x <= x_max &&
			p.barycenter.y >= y_min && p.barycenter.y <= y_max &&
			p.barycenter.z >= z_min && p.barycenter.z <= z_max;
}

istream & operator>>(istream & is, include & a)
{
	is >> a.x_min >> a.x_max;
	is >> a.y_min >> a.y_max;
	is >> a.z_min >> a.z_max;
	is >> a.p.x >> a.p.y >> a.p.z;
	return is;
}

