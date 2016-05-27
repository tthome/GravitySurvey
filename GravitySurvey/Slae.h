#ifndef SLAE_H
#define SLAE_H

#include <vector>

using namespace std;

class Slae
{
public:
	static vector<double> solveGauss(const vector<vector<double>> a, const vector<double> b);
};

#endif // SLAE_H


