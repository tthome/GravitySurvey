#ifndef INVERSEM_H
#define INVERSEM_H

#include "Inverse.h"

using namespace System;

namespace Shell
{
	public ref class InverseM
	{
		Inverse* inverse;

	public:

		InverseM();
		~InverseM();
		void InputArea(String^ path);
	};
}

#endif // INVERSEM_H
