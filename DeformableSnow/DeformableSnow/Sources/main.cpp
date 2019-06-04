#include "stdafx.h"
#include "ToonRoot.h"

int main(void)
{ 
	Toon::ToonRoot root;

	if (!root.initialize(true, "DeformableSnowSimulation", "../Resources/engine_config.ini"))
	{
		return -1;
	}

	int exitCode = root.runMainLoop();
	return exitCode;
}