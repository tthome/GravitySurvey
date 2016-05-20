#ifndef INVERSE_H
#define INVERSE_H

#include <string>
#include "area.h"

using namespace std;

class inverse
{
	area a;
	vector<pair<point, vector3>> receivers;
public:
	void input(const string & fn_area, const string & fn_receivers);
};

#endif

