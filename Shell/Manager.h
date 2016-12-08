#ifndef MANAGER_H
#define MANAGER_H

#include <string>

#include "Inverse.h"

using namespace System;

namespace Shell
{
	public ref class Manager
	{
		Inverse* inverse;
		
	public:

		Manager();
		~Manager();
		void Run();
		void InputArea(String^ path);
	};
}

#endif // MANAGER_H
