#include "SnowApplication.hpp"
#include "FileSystem.hpp"
#include "Obfuscator.hpp"

SnowApplication::SnowApplication() {
}

SnowApplication::~SnowApplication() {
}

bool SnowApplication::initApplication(void)
{
	if (!Application::initContext())
		return false;

	auto& fs = FileSystem::getMutableInstance();
	fs.setRootPath(OBFUSCATE("./"));
	fs.addTable(OBFUSCATE("Material"), OBFUSCATE("resources/texture/"));
	fs.addTable(OBFUSCATE("Resource"), OBFUSCATE("resources/resource/"));
	
	return true;
}

void SnowApplication::updateScene(float dt) {
}

void SnowApplication::drawScene(void) const {
}

void SnowApplication::keyCallback(int key, int scancode, int action, int mode) {
}

void SnowApplication::mousePosCallback(double xpos, double ypos) {
}

void SnowApplication::mouseBtnCallback(int btn, int action, int mods) {
}

void SnowApplication::scrollCallback(double xoffset, double yoffset) {
}

void SnowApplication::resizingCallback(int newWidth, int newHeight) {
}
