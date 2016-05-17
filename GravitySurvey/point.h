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
};

#endif 

