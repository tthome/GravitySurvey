#include "Inverse.h"

#include <fstream>

void Inverse::input(const string& areaPath, const string& receiversPath)
{
	area.generate(areaPath);
	nCubes = area.cubes.size();

	ifstream ifs(receiversPath);
	ofstream ofs("../xgz.txt");
	ifs >> nReceivers;
	receivers.resize(nReceivers);
	for (int i = 0; i < nReceivers; i++)
	{
		ifs >> receivers[i].first.x >> receivers[i].first.y >> receivers[i].first.z;
		receivers[i].second = area.computeG(receivers[i].first);
		ofs << receivers[i].first.x << "\t" << receivers[i].second.z << endl;
	}
	ifs.close();
	ofs.close();

	matrixA.resize(nCubes);
	for (int i = 0; i < matrixA.size(); i++)
	{
		matrixA[i].resize(nCubes);
	}

	vectorB.resize(nCubes);
}

void Inverse::makeMatrixA()
{
	for (int q = 0; q < matrixA.size(); q++)
	{
		for (int s = 0; s < matrixA[q].size(); s++)
		{
			matrixA[q][s] = 0;
			for (int i = 0; i < nReceivers; i++)
			{
				matrixA[q][s] += area.cubes[q].computeG(receivers[i].first).z * area.cubes[s].computeG(receivers[i].first).z;
			}
		}
	}
}

void Inverse::makeVectorB()
{
	for (int q = 0; q < matrixA.size(); q++)
	{
		vectorB[q] = 0;
		for (int i = 0; i < nReceivers; i++)
		{
			vectorB[q] += area.cubes[q].computeG(receivers[i].first).z * receivers[i].second.z;
		}
	}
}

void Inverse::calculate()
{
	makeMatrixA();
	makeVectorB();
}

