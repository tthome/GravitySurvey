#ifndef POINT_H
#define POINT_H

template <typename T>
class PointT;
typedef PointT<double> Point;

template <typename T>
class PointT
{
public:
	T x, y, z;
	PointT();
	template <typename U>
	PointT(U x, U y, U z);
};

template <typename T>
PointT<T>::PointT()
{
	x = y = z = T(0);
}

template <typename T>
template <typename U>
PointT<T>::PointT(U x, U y, U z)
{
	this->x = T(x);
	this->y = T(y);
	this->z = T(z);
}

#endif // POINT_H


