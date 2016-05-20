#ifndef INVERSE_H
#define INVERSE_H

#include <string>
#include "area.h"
#include "inverse_config.h"

using namespace std;

class inverse
{
	area a;
	size_t K, N;
	vector<pair<point, vector3>> receivers;
	inverse_config cfg;
public:
	void input(const string & fn_area, const string & fn_receivers, const string & fn_config);
};

#endif

