#ifndef SNOW_APPLICATION_HPP
#define SNOW_APPLICATION_HPP

#include "Application.hpp"

class SnowApplication : public Application {
public:
	SnowApplication();
	~SnowApplication();
public:	
	bool initApplication(void);
protected:
	void updateScene(float dt) override;
	void drawScene(void) const override;
	void keyCallback(int key, int scancode, int action, int mode) override;
	void mousePosCallback(double xpos, double ypos) override;
	void mouseBtnCallback(int btn, int action, int mods) override;
	void scrollCallback(double xoffset, double yoffset) override;
	void resizingCallback(int newWidth, int newHeight) override;
private:
protected:
};

#endif //SNOW_APPLICATION_HPP