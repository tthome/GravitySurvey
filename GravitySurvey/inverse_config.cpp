#include "inverse_config.h"

inverse_config::inverse_config()
{
	use_alpha = true; // Использовать регуляризацию по альфа
	use_gamma = true; // Использовать регуляризацию по гамма
	alpha0 = 1e-15; // Начальное значение alpha
	dalpha = 2.0; // Шаг увеличения alpha
	alpha_coeff = 10.0; // Во сколько раз может возрати значение функционала
	gamma0 = 1e-15; // Начальное значение gamma
	dgamma = 2.0; // Шаг увеличения gamma
	gamma_coeff = 3.0; // На сколько порядков может возрасти значение функционала
	gamma_diff = 1e-5; // Разница между соседями, которую считаем уже разницей
}

istream & operator>>(istream & is, inverse_config & a)
{
	is >> a.use_alpha >> a.use_gamma
			>> a.alpha0 >> a.dalpha >> a.alpha_coeff
			>> a.gamma0 >> a.dgamma >> a.gamma_coeff
			>> a.gamma_diff;
	return is;
}

ostream & operator<<(ostream & os, const inverse_config & a)
{
	os << "-- BEGIN CONFIG --" << endl;
	os << "use_alpha   = " << a.use_alpha << endl
			<< "use_gamma   = " << a.use_gamma << endl
			<< "alpha0      = " << a.alpha0 << endl
			<< "dalpha      = " << a.dalpha << endl
			<< "alpha_coeff = " << a.alpha_coeff << endl
			<< "gamma0      = " << a.gamma0 << endl
			<< "dgamma      = " << a.dgamma << endl
			<< "gamma_coeff = " << a.gamma_coeff << endl
			<< "gamma_diff  = " << a.gamma_diff << endl;
	os << "-- END CONFIG --" << endl;
	return os;
}

