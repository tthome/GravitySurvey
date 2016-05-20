#ifndef POINT_H
#define POINT_H

template <typename T>
class point_t;
typedef point_t<double> point;

template <typename T>
class point_t
{
public:
	T x, y, z;
	point_t();
	template <typename U>
	point_t(U x, U y, U z);
};

template <typename T>
point_t<T>::point_t()
{
	x = y = z = static_cast<T>(0);
}

template <typename T>
template <typename U>
point_t<T>::point_t(U x, U y, U z)
{
	this->x = static_cast<T>(x);
	this->y = static_cast<T>(y);
	this->z = static_cast<T>(z);
}

#endif 

