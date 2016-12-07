#ifndef INVERSE_H
#define INVERSE_H

#include "Area.h"
#include "Config.h"

using namespace std;

class Inverse
{
	Area area;
	vector<pair<Point, Vector3>> receivers;

	double alpha = 0;
	vector<double> gamma;

	Config config;

	vector<vector<double>> createA() const;
	vector<double> createB() const;
	vector<vector<double>> createC() const;

	double computeF(const vector<double>& solution);
	double computeAlpha();
	double computeGamma();

public:

	void input(const string& areaPath, const string& receiversPath, const string& configPath);
	void inputArea(const string& path);
	void inputReceivers(const string& path);
	void inputConfig(const string& path);
	void calculate();
	void printSolution(const string& path);
};

#endif // INVERSE_H


