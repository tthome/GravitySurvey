#ifndef AREA_H
#define AREA_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "point.h"
#include "include.h"
#include "cube.h"

using namespace std;

class area
{
public:
	vector<point> nodes;
	vector<cube> cubes;
	vector3 calc_g(const point & m) const;
	void generate(const string & filename);
};

#endif

