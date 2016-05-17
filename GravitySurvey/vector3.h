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
};

#endif

