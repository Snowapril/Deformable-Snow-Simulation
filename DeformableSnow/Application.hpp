#ifndef APPLICATION_HPP
#define APPLICATION_HPP

struct GLFWwindow;

class Application {
public:
	Application();
	virtual ~Application();
public:
	bool initContext(void);
	void registerCallback(void);
	void runApplication(void);

	GLFWwindow const* getAppWindow(void) const {
		return window;
	}
	inline float getAspectRatio(void) const {
		return static_cast<float>(clientWidth) / clientHeight;
	}
protected:
	virtual void updateScene(float dt) = 0;
	virtual void drawScene(void) const = 0;
	virtual void keyCallback(int key, int scancode, int action, int mode) = 0;
	virtual void mousePosCallback(double xpos, double ypos) = 0;
	virtual void mouseBtnCallback(int btn, int action, int mods) = 0;
	virtual void scrollCallback(double xoffset, double yoffset) = 0;
	virtual void resizingCallback(int newWidth, int newHeight);
protected:	
	GLFWwindow* window;
	int clientWidth;
	int clientHeight;
};

#endif //APPLICATION_HPP