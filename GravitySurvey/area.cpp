#include "Area.h"

#include <iostream>
#include <fstream>
#include <string>

Vector3 Area::computeG(const Point& receiverPoint) const
{
	Vector3 result(0, 0, 0);
	for (int i = 0; i < cubes.size(); i++)
	{
		result = result + cubes[i].computeG(receiverPoint); // Rho(k)* ??
	}
	return result;
}

void Area::generate(const string& path)
{
	ifstream ifs(path);
	if (!ifs.good())
	{
		cerr << "Error: " << path << " not good." << endl;
		system("Pause");
		exit(EXIT_FAILURE);
	}

	double xMin, xMax, yMin, yMax, zMin, zMax;
	ifs >> xMin >> xMax >> yMin >> yMax >> zMin >> zMax;
	int nX, nY, nZ;
	ifs >> nX >> nY >> nZ;

	int nIncludes;
	ifs >> nIncludes;
	vector<Include> includes;
	includes.resize(nIncludes);
	for (int i = 0; i != nIncludes; i++)
	{
		ifs >> includes[i];
	}
	ifs.close();

	double hx = (xMax - xMin) / double(nX);
	double hy = (yMax - yMin) / double(nY);
	double hz = (zMax - zMin) / double(nZ);
	nodes.resize((nX + 1) * (nY + 1) * (nZ + 1));
	for (int i = 0, m = 0; i <= nX; i++)
	{
		double xCurrent = xMin + hx * double(i);
		for (int j = 0; j <= nY; j++)
		{
			double yCurrent = yMin + hy * double(j);
			for (int k = 0; k <= nZ; k++)
			{
				double zCurrent = zMin + hz * double(k);
				nodes[m].x = xCurrent;
				nodes[m].y = yCurrent;
				nodes[m].z = zCurrent;
				m++;
			}
		}
	}

	cubes.resize(nX * nY * nZ);
	for (int i = 0, m = 0; i < nX; i++)
	{
		for (int j = 0; j < nY; j++)
		{
			for (int k = 0; k < nZ; k++)
			{
				cubes[m].nodes[0] = nodes.data() + (i * (nY + 1) + j) * (nZ + 1) + k;
				cubes[m].nodes[1] = nodes.data() + ((i + 1) * (nY + 1) + j) * (nZ + 1) + k;
				cubes[m].nodes[2] = nodes.data() + (i * (nY + 1) + j + 1) * (nZ + 1) + k;
				cubes[m].nodes[3] = nodes.data() + ((i + 1) * (nY + 1) + j + 1) * (nZ + 1) + k;
				cubes[m].nodes[4] = nodes.data() + (i * (nY + 1) + j) * (nZ + 1) + k + 1;
				cubes[m].nodes[5] = nodes.data() + ((i + 1) * (nY + 1) + j) * (nZ + 1) + k + 1;
				cubes[m].nodes[6] = nodes.data() + (i * (nY + 1) + j + 1) * (nZ + 1) + k + 1;
				cubes[m].nodes[7] = nodes.data() + ((i + 1) * (nY + 1) + j + 1) * (nZ + 1) + k + 1;
				cubes[m].initialize();
				for (int ii = 0; ii < includes.size(); ii++)
				{
					if (includes[ii].isInside(cubes[m]))
					{
						cubes[m].rho = includes[ii].rho;
					}
				}
				m++;
			}
		}
	}
}

