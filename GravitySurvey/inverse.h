#ifndef INVERSE_H
#define INVERSE_H

#include "Area.h"

using namespace std;

class Inverse
{
	Area area;
	vector<pair<Point, Vector3>> receivers;
	int nCubes = 0, nReceivers = 0;

	vector<vector<double>> matrixA;
	vector<double> vectorB;
public:
	void input(const string& areaPath, const string& receiversPath);
	void makeMatrixA();
	void makeVectorB();
	void calculate();
};

#endif // INVERSE_H


