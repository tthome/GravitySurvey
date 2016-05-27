#ifndef VECTOR3_H
#define VECTOR3_H

template <typename T>
class vector3_t;
typedef vector3_t<double> vector3;

template <typename T>
class vector3_t
{
public:
	T x, y, z;
	vector3_t();
	template <typename U, typename V, typename R>
	vector3_t(U x, V y, R z);
	vector3_t<T> operator +(const vector3_t<T>& v) const;
	template <typename U>
	friend vector3_t<U> operator *(const U& a, const vector3_t<U>& v);
};

template <typename T>
vector3_t<T>::vector3_t()
{
	x = y = z = static_cast<T>(0);
}

template <typename T>
template <typename U, typename V, typename R>
vector3_t<T>::vector3_t(U x, V y, R z)
{
	this->x = static_cast<T>(x);
	this->y = static_cast<T>(y);
	this->z = static_cast<T>(z);
}

template <typename T>
vector3_t<T> vector3_t<T>::operator+(const vector3_t<T>& v) const
{
	return vector3_t<T>(x + v.x, y + v.y, z + v.z);
}

template <typename U>
vector3_t<U> operator*(const U& a, const vector3_t<U>& v)
{
	return vector3_t<U>(a * v.x, a * v.y, a * v.z);
}

#endif

