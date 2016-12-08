#include "Stdafx.h"
#include "InverseM.h"

#include <string>

using namespace std;

namespace Shell
{
	InverseM::InverseM()
	{
		inverse = new Inverse();
	}

	InverseM::~InverseM()
	{
		if (inverse != nullptr)
		{
			delete inverse;
			inverse = nullptr;
		}
	}	

	void MarshalString(String ^s, string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void InverseM::InputArea(String^ path)
	{
		Console::WriteLine("InputArea");
		string s;
		MarshalString(path, s);
		inverse->inputArea(s);
	}	
}
