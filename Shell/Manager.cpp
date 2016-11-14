#include "Stdafx.h"

#include "Manager.h"
#include "Inverse.h"

namespace Wrapper
{
	void Manager::Run()
	{
		Inverse inverse;
		inverse.input("../../../Area.txt", "../../../Receivers.txt", "../../../Config.txt");
		inverse.calculate();
	}
}

