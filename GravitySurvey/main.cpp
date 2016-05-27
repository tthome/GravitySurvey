#include "Inverse.h"

int main()
{
	Inverse inverse;
	inverse.input("../Area.txt", "../Receivers.txt");
	inverse.calculate();
	return 0;
}

