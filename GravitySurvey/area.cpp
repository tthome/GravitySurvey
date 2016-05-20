#include "area.h"

vector3 area::calc_g(const point & m) const
{
	vector3 result(0, 0, 0);
	for (size_t i = 0; i < cubes.size(); i++)
		result = result + cubes[i].calc_g(m);
	return result;
}

void area::generate(const string & filename)
{
	ifstream ifs(filename);
	if (!ifs.good())
	{
		cerr << "Error: " << filename << " not good." << endl;
		exit(EXIT_FAILURE);
	}

	double x_min, x_max, y_min, y_max, z_min, z_max;
	ifs >> x_min >> x_max >> y_min >> y_max >> z_min >> z_max;
	size_t x_num, y_num, z_num;
	ifs >> x_num >> y_num >> z_num;

	size_t inc_num;
	ifs >> inc_num;
	vector<include> includes;
	includes.resize(inc_num);
	for (size_t i = 0; i != inc_num; i++)
		ifs >> includes[i];

	if (!ifs.good())
	{
		cerr << "Error: " << filename << " not good." << endl;
		exit(EXIT_FAILURE);
	}
	ifs.close();

	double hx = (x_max - x_min) / static_cast<double>(x_num),
		hy = (y_max - y_min) / static_cast<double>(y_num),
		hz = (z_max - z_min) / static_cast<double>(z_num);
	nodes.resize((x_num + 1) * (y_num + 1) * (z_num + 1));
	for (size_t i = 0, m = 0; i <= x_num; i++)
	{
		double x_curr = x_min + hx * static_cast<double>(i);
		for (size_t j = 0; j <= y_num; j++)
		{
			double y_curr = y_min + hy * static_cast<double>(j);
			for (size_t k = 0; k <= z_num; k++)
			{
				double z_curr = z_min + hz * static_cast<double>(k);
				nodes[m].x = x_curr;
				nodes[m].y = y_curr;
				nodes[m].z = z_curr;
				m++;
			}
		}
	}

	cubes.resize(x_num * y_num * z_num);
	for (size_t i = 0, m = 0; i < x_num; i++)
	{
		for (size_t j = 0; j < y_num; j++)
		{
			for (size_t k = 0; k < z_num; k++)
			{
				cubes[m].nodes[0] = nodes.data() + (i * (y_num + 1) + j) * (z_num + 1) + k;
				cubes[m].nodes[1] = nodes.data() + ((i + 1) * (y_num + 1) + j) * (z_num + 1) + k;
				cubes[m].nodes[2] = nodes.data() + (i * (y_num + 1) + j + 1) * (z_num + 1) + k;
				cubes[m].nodes[3] = nodes.data() + ((i + 1) * (y_num + 1) + j + 1) * (z_num + 1) + k;
				cubes[m].nodes[4] = nodes.data() + (i * (y_num + 1) + j) * (z_num + 1) + k + 1;
				cubes[m].nodes[5] = nodes.data() + ((i + 1) * (y_num + 1) + j) * (z_num + 1) + k + 1;
				cubes[m].nodes[6] = nodes.data() + (i * (y_num + 1) + j + 1) * (z_num + 1) + k + 1;
				cubes[m].nodes[7] = nodes.data() + ((i + 1) * (y_num + 1) + j + 1) * (z_num + 1) + k + 1;
				cubes[m].init();
				for (size_t ii = 0; ii < includes.size(); ii++)
					if (includes[ii].inside(cubes[m]))
						cubes[m].p = includes[ii].p;
				m++;
			}
		}
	}
}

