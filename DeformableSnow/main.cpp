#include "SnowApplication.hpp"

int main(void) {

	SnowApplication app;
	if (app.initContext()) {
		// do stuff
		app.registerCallback();
	}
	
	return 0;
}