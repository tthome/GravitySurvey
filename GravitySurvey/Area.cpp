#include "Area.h"

#include <iostream>
#include <fstream>
#include <string>

Vector3 Area::computeG(const Point& receiverPoint) const
{
	Vector3 result(0, 0, 0);
	for (int i = 0; i < cubes.size(); i++)
	{
		result = result + cubes[i].rho * cubes[i].computeG(receiverPoint);
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
				if (i > 0) cubes[m].neighbors[0] = cubes.data() + ((i - 1) * nY + j) * nZ + k;
				if (i < nX - 1) cubes[m].neighbors[1] = cubes.data() + ((i + 1) * nY + j) * nZ + k;
				if (j > 0) cubes[m].neighbors[2] = cubes.data() + (i * nY + j - 1) * nZ + k;
				if (j < nY - 1) cubes[m].neighbors[3] = cubes.data() + (i * nY + j + 1) * nZ + k;
				if (k > 0) cubes[m].neighbors[4] = cubes.data() + (i * nY + j) * nZ + k - 1;
				if (k < nZ - 1) cubes[m].neighbors[5] = cubes.data() + (i * nY + j) * nZ + k + 1;
				cubes[m].id = m;
				m++;
			}
		}
	}
}

