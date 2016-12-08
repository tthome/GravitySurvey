#include "Stdafx.h"
#include "Manager.h"

#include <string>

using namespace std;

namespace Shell
{
	Manager::Manager()
	{
		inverse = new Inverse();
	}

	Manager::~Manager()
	{
		if (inverse != nullptr)
		{
			delete inverse;
			inverse = nullptr;
		}
	}

	void Manager::Run()
	{
		
		//inverse->input("../../../Area.txt", "../../../Receivers.txt", "../../../Config.txt");
		//inverse->calculate();
	}

	void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void Manager::InputArea(String^ path)
	{
		Console::WriteLine("InputArea");
		string s;
		MarshalString(path, s);
		inverse->inputArea(s);
	}

	
}

