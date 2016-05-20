#ifndef CUBE_H
#define CUBE_H

#include "point.h"
#include "vector3.h"

/*   _____________
*  /|6          /|7    ^ z
* /____________/ |     |  ^ y
* |4|          |5|     | /
* | |          | |     |/----> x
* | |          | |
* | |          | |
* | |__________|_|
* | /2         | /3
* |/___________|/
* 0            1
*/

/* Neighbors:
* 0 - left
* 1 - right
* 2 - front
* 3 - back
* 4 - bottom
* 5 - top
*/

class cube
{
public:
	point * nodes[8];
	point barycenter;
	cube * neighbors[6];
	vector3 p;
	double mes;
	size_t num;
	cube();
	void init();
};

#endif

