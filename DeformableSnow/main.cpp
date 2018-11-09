#include "SnowApplication.hpp"
#include "Logger.hpp"

int main(void) {

	INIT_LOGGER();

	SnowApplication app;
	if (app.initApplication()) {
		// do stuff
		app.registerCallback();
		app.runApplication();
	}
	
	return 0;
}