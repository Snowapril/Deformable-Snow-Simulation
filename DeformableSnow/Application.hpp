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
private:
protected:
	GLFWwindow* window;
	int clientWidth;
	int clientHeight;
};

#endif //APPLICATION_HPP