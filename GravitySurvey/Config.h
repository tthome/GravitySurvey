#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>

using namespace std;

class Config
{
public:

	bool useAlpha;
	bool useGamma;
	double alphaStart;
	double alphaStep;
	double alphaCoeff;
	double gammaStart;
	double gammaStep;
	double gammaCoeff;
	double gammaDiff;

	Config();

	friend istream& operator >>(istream& is, Config& config);
	friend ostream& operator <<(ostream& os, const Config& config);
};

#endif // CONFIG_H


