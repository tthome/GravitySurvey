#include "Inverse.h"
#include "Slae.h"

#include <fstream>
#include <iostream>

void Inverse::input(const string& areaPath, const string& receiversPath, const string& configPath)
{
	inputArea(areaPath);
	inputReceivers(receiversPath);
	inputConfig(configPath);	
}

void Inverse::inputArea(const string& path)
{
	area.generate(path);
}

void Inverse::inputReceivers(const string& path)
{
	ifstream ifs(path);
	ofstream ofs("../../../Analytical.txt");
	int nReceivers;
	ifs >> nReceivers;
	receivers.resize(nReceivers);
	for (int i = 0; i < receivers.size(); i++)
	{
		ifs >> receivers[i].first.x >> receivers[i].first.y >> receivers[i].first.z;
		receivers[i].second = area.computeG(receivers[i].first);
		ofs << receivers[i].first.x << "\t" << receivers[i].second.z << endl;
	}
	ifs.close();
	ofs.close();
}

void Inverse::inputConfig(const string& path)
{
	ifstream ifs(path);
	if (ifs.good())
	{
		ifs >> config;
		ifs.close();
	}
}

vector<vector<double>> Inverse::createA() const
{
	vector<vector<double>> a(area.cubes.size());
	for (int q = 0; q < area.cubes.size(); q++)
	{
		a[q].resize(area.cubes.size());
		for (int s = 0; s < area.cubes.size(); s++)
		{
			a[q][s] = 0;
			for (int i = 0; i < receivers.size(); i++)
			{
				a[q][s] += area.cubes[q].computeG(receivers[i].first).z * area.cubes[s].computeG(receivers[i].first).z;
			}
		}
	}
	return a;
}

vector<double> Inverse::createB() const
{
	vector<double> b(area.cubes.size());
	for (int q = 0; q < area.cubes.size(); q++)
	{
		b[q] = 0;
		for (int i = 0; i < receivers.size(); i++)
		{
			b[q] += area.cubes[q].computeG(receivers[i].first).z * receivers[i].second.z;
		}
	}
	return b;
}

vector<vector<double>> Inverse::createC() const
{
	vector<vector<double>> c(area.cubes.size());
	for (int i = 0; i < area.cubes.size(); i++)
	{
		c[i].resize(area.cubes.size());
		for (int j = 0; j < area.cubes.size(); j++)
		{
			c[i][j] = 0;
			if (i == j)
			{
				int count = 0;
				double gammaSum = 0;
				for (int k = 0; k < 6; k++)
				{
					if (area.cubes[i].neighbors[k])
					{
						count++;
						gammaSum += gamma[area.cubes[i].neighbors[k]->id];
					}
				}
				c[i][j] = gamma[i] * count + gammaSum;
			}
			else if (area.cubes[i].isNeighbor(area.cubes[j]))
			{
				c[i][j] = -(gamma[i] + gamma[j]);
			}
		}
	}
	return c;
}

double Inverse::computeF(const vector<double>& solution)
{
	for (int i = 0; i < area.cubes.size(); i++)
	{
		area.cubes[i].rho = solution[i];
	}

	double f = 0;
	for (int i = 0; i < receivers.size(); i++)
	{
		double gr = receivers[i].second.z;
		double ga = area.computeG(receivers[i].first).z;
		f += pow(gr - ga, 2);
	}
	return f;
}

double Inverse::computeAlpha()
{
	double f = 0;
	for (int k = 0; k < area.cubes.size(); k++)
	{
		f += alpha * pow(area.cubes[k].rho, 2);
	}
	return f;
}

double Inverse::computeGamma()
{
	double f = 0;
	for (int k = 0; k < area.cubes.size(); k++)
	{
		double sum = 0;
		for (int m = 0; m < 6; m++)
		{
			if (area.cubes[k].neighbors[m])
			{
				sum += pow(area.cubes[k].rho - area.cubes[k].neighbors[m]->rho, 2);
			}
		}
		f += gamma[k] * sum;
	}
	return f;
}

void Inverse::calculate()
{
	cout << "Creating A.." << endl;
	vector<vector<double>> a = createA();

	cout << "Creating b.." << endl;
	vector<double> b = createB();

	cout << "Solving SLAE.." << endl;
	vector<double> x = Slae::solveGauss(a, b);

	vector<vector<double>> a1(a);

	double currentF, previousF;

	if (config.useAlpha)
	{
		cout << "Alpha regularization.." << endl;
		alpha = config.alphaStart;
		currentF = previousF = computeF(x);
		cout << scientific << "::PreviousF: " << previousF << endl;
		while (currentF <= previousF * config.alphaCoeff)
		{
			for (int i = 0; i < a1.size(); i++)
			{
				a1[i][i] += alpha;
			}
			x = Slae::solveGauss(a1, b);
			currentF = computeF(x);
			cout << scientific << "::CurrentF: " << currentF << " " << currentF / previousF << endl;
			if (currentF <= previousF * config.alphaCoeff)
			{
				alpha *= config.alphaStep;
			}
		}
		cout << scientific << "::Alpha: " << alpha << endl;
	}
	else
	{
		alpha = 0;
	}

	if (config.useGamma)
	{
		cout << "Gamma regularization.." << endl;
		x = Slae::solveGauss(a, b);
		a1 = a;
		gamma.resize(area.cubes.size());
		for (int i = 0; i < gamma.size(); i++)
		{
			gamma[i] = config.gammaStart;
		}
		currentF = previousF = computeF(x);
		cout << scientific << "::PreviousF: " << previousF << endl;
		while (currentF <= previousF * config.gammaCoeff)
		{
			vector<vector<double>> c = createC();
			for (int i = 0; i < a1.size(); i++)
			{
				for (int j = 0; j < a1[0].size(); j++)
				{
					a1[i][i] += c[i][j];
				}
			}
			x = Slae::solveGauss(a1, b);
			currentF = computeF(x);
			cout << scientific << "::CurrentF: " << currentF << " " << currentF / previousF << endl;
			if (currentF <= previousF * config.gammaCoeff)
			{
				for (int i = 0; i < gamma.size(); i++)
				{
					gamma[i] *= config.gammaStep;
				}
			}
		}
	}
	else
	{
		gamma.resize(area.cubes.size());
		for (int i = 0; i < gamma.size(); i++)
		{
			gamma[i] = 0;
		}
	}

	x = Slae::solveGauss(a, b);
	currentF = computeF(x);
	cout << scientific << "Functional [STD]: " << currentF << endl;
	for (int i = 0; i < a.size(); i++)
	{
		a[i][i] += alpha;
	}
	vector<vector<double>> c = createC();
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			a[i][i] += c[i][j];
		}
	}
	x = Slae::solveGauss(a, b);
	currentF = computeF(x) + computeAlpha() + computeGamma();
	cout << scientific << "Functional [REG]: " << currentF << endl;

	for (int i = 0; i < area.cubes.size(); i++)
	{
		area.cubes[i].rho = x[i];
	}
	ofstream ofs("../../../Calculated.txt");
	if (ofs.good())
	{
		for (int i = 0; i < receivers.size(); i++)
		{
			ofs << receivers[i].first.x << "\t" << area.computeG(receivers[i].first).z << endl;
		}
		ofs.close();
	}

	printSolution("../../../Solution.txt");
}

void Inverse::printSolution(const string& path)
{
	ofstream ofs(path);
	if (ofs.good())
	{
		Cube startCube = area.cubes[0];
		while (true)
		{
			Cube lineCube = startCube;
			while (true)
			{
				ofs << scientific << lineCube.rho << "\t";
				if (lineCube.neighbors[1])
				{
					lineCube = *lineCube.neighbors[1];
				}
				else break;
			}
			ofs << endl;
			if (startCube.neighbors[5])
			{
				startCube = *startCube.neighbors[5];
			}
			else break;
		}
		ofs.close();
	}
}

