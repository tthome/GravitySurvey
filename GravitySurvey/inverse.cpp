#include "inverse.h"

void inverse::input(const string & fn_area, const string & fn_receivers, const string & fn_config)
{
	a.generate(fn_area);
	K = a.cubes.size();

	ifstream ifs(fn_receivers);
	if (!ifs.good())
	{
		cerr << "Error: " << fn_receivers << " not good." << endl;
		exit(EXIT_FAILURE);
	}

	ifs >> N;
	receivers.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		ifs >> receivers[i].first.x >> receivers[i].first.y >> receivers[i].first.z;
	}
	ifs.close();

	ifs.open(fn_config);
	if (ifs.good())
	{
		ifs >> cfg;
		ifs.close();
	}
	cout << cfg;
}
