#ifndef SLAE_H
#define SLAE_H

#include <vector>

using namespace std;

class Slae
{
public:
	vector<double> solveGauss(vector<vector<double>> a, vector<double> b);
};

#endif // SLAE_H
