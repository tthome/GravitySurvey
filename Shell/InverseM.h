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
		void InputReceivers(String^ path);
		void InputConfig(String^ path);
		void Calculate();
	};
}

#endif // INVERSEM_H
