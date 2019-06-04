#include "stdafx.h"

// For enabling optimus feature of laptops.
extern "C"
{
	_declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}