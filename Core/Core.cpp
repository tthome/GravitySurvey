#include "stdafx.h"

#include "Core.h"
#include "Inverse.h"

namespace Core
{
	void Manager::Run()
	{
		Inverse inverse;
		inverse.input("../../../Area.txt", "../../../Receivers.txt", "../../../Config.txt");
		inverse.calculate();
	}
}

