#include "stdafx.h"
#include "ToonRoot.h"

int main(void)
{ 
	Toon::ToonRoot root;
	int exitCode { -1 };

	bool bInitResult = root.initFromINIFile("../Resources/engine_config.ini");
	root.initSceneObjects();

	if (bInitResult == true) 
		exitCode = root.runMainLoop();

	return exitCode;
}