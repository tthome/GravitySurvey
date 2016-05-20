#include "inverse.h"

void inverse::input(const string & fn_area, const string & fn_receivers)
{
	a.generate(fn_area);

	ifstream ifs(fn_receivers);
	ofstream ofs("../xgz.txt");
	size_t r_num;
	ifs >> r_num;
	receivers.resize(r_num);
	for (size_t i = 0; i < r_num; i++)
	{
		ifs >> receivers[i].first.x >> receivers[i].first.y >> receivers[i].first.z;
		receivers[i].second = a.calc_g(receivers[i].first);
		ofs << receivers[i].first.x << "\t" << receivers[i].second.z << endl;
	}
	ifs.close();
	ofs.close();
}

