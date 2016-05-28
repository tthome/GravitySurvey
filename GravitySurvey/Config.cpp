#include "Config.h"

Config::Config()
{
	useAlpha = true;
	useGamma = true;
	alphaStart = 1e-10;
	alphaStep = 2.0;
	alphaCoeff = 10.0;
	gammaStart = 1e-10;
	gammaStep = 2.0;
	gammaCoeff = 3.0;
	gammaDiff = 1e-5;
}

istream& operator>>(istream& is, Config& config)
{
	is >> config.useAlpha >> config.useGamma;
	is >> config.alphaStart >> config.alphaStep >> config.alphaCoeff;
	is >> config.gammaStart >> config.gammaStep >> config.gammaCoeff >> config.gammaDiff;
	return is;
}

ostream& operator<<(ostream& os, const Config& config)
{
	os << config.useAlpha << endl;
	os << config.useGamma << endl;
	os << config.alphaStart << endl;
	os << config.alphaStep << endl;
	os << config.alphaCoeff << endl;
	os << config.gammaStart << endl;
	os << config.gammaStep << endl;
	os << config.gammaCoeff << endl;
	os << config.gammaDiff << endl;		
	return os;
}
