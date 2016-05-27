#ifndef VECTOR3_H
#define VECTOR3_H

template <typename T>
class Vector3T;
typedef Vector3T<double> Vector3;

template <typename T>
class Vector3T
{
public:
	T x, y, z;
	Vector3T();
	template <typename U, typename V, typename R>
	Vector3T(U x, V y, R z);
	Vector3T<T> operator +(const Vector3T<T>& vector) const;
	template <typename U>
	friend Vector3T<U> operator *(const U& scalar, const Vector3T<U>& vector);
};

template <typename T>
Vector3T<T>::Vector3T()
{
	x = y = z = T(0);
}

template <typename T>
template <typename U, typename V, typename R>
Vector3T<T>::Vector3T(U x, V y, R z)
{
	this->x = T(x);
	this->y = T(y);
	this->z = T(z);
}

template <typename T>
Vector3T<T> Vector3T<T>::operator+(const Vector3T<T>& vector) const
{
	return Vector3T<T>(x + vector.x, y + vector.y, z + vector.z);
}

template <typename U>
Vector3T<U> operator*(const U& scalar, const Vector3T<U>& vector)
{
	return Vector3T<U>(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}

#endif // VECTOR3_H


