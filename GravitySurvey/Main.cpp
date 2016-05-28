#include "Inverse.h"

int main()
{
	Inverse inverse;
	inverse.input("../Area.txt", "../Receivers.txt", "../Config.txt");
	inverse.calculate();

	system("Pause");
	return 0;
}

