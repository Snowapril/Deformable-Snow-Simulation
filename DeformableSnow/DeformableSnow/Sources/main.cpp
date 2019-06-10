#include "stdafx.h"
#include "ToonRoot.h"

int main(void)
{ 
	Toon::ToonRoot root;
	int exitCode { -1 };

	bool bInitResult = root.initialize("../Resources/engine_config.ini");

	if (bInitResult == true) 
		exitCode = root.runMainLoop();

	return exitCode;
}