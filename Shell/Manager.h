#ifndef MANAGER_H
#define MANAGER_H

#include <string>

using namespace System;

namespace Shell
{
	public ref class Manager
	{
		
	public:
		Manager();
		~Manager();
		void Run();
		void InputArea(String^ path);

	private:
		Inverse inverse;
	};
}

#endif // MANAGER_H
