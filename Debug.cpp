#include "Debug.h"

void Debug::PrintDebugText(std::string x)
{	
	std::string output = x + "\n";
	OutputDebugStringA(output.c_str());
}
