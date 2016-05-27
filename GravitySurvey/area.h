#ifndef AREA_H
#define AREA_H

#include "Point.h"
#include "Include.h"
#include "Cube.h"

#include <vector>

using namespace std;

class Area
{
public:
	vector<Point> nodes;
	vector<Cube> cubes;
	Vector3 computeG(const Point& receiverPoint) const;
	void generate(const string& path);
};

#endif // AREA_H


