#include "Slae.h"

vector<double> Slae::solveGauss(const vector<vector<double>>& a, const vector<double>& b)
{
	int size = b.size();

	vector<vector<double>> ext;
	ext.resize(size);
	for (int i = 0; i < size; i++)
	{
		ext[i].resize(size + 1);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ext[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		ext[i][size] = b[i];
	}

	vector<double> x(b);

	for (int k = 1; k < size; k++)
	{
		for (int j = k; j < size; j++)
		{
			double m = ext[j][k - 1] / ext[k - 1][k - 1];
			for (int i = 0; i < size + 1; i++)
			{
				ext[j][i] -= m * ext[k - 1][i];
			}
			x[j] = x[j] - m * x[k - 1];
		}
	}

	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < size; j++)
		{
			x[i] -= ext[i][j] * x[j];
		}
		x[i] /= ext[i][i];
	}

	return x;
}

