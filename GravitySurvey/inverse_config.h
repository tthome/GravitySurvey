#ifndef INVERSE_CONFIG_H
#define INVERSE_CONFIG_H

#include <fstream>

using namespace std;

class inverse_config
{
public:
	bool use_alpha; // Использовать регуляризацию по альфа
	bool use_gamma; // Использовать регуляризацию по гамма
	double alpha0; // Начальное значение alpha
	double dalpha; // Шаг увеличения alpha
	double alpha_coeff; // Во сколько раз может возрати значение функционала
	double gamma0; // Начальное значение gamma
	double dgamma; // Шаг увеличения gamma
	double gamma_coeff; // На сколько порядков может возрасти значение функционала
	double gamma_diff; // Разница между соседями, которую считаем уже разницей
	inverse_config();
	friend istream & operator >>(istream & is, inverse_config & a);
	friend ostream & operator <<(ostream & os, const inverse_config & a);
};

#endif

