#include "Application.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Logger.hpp"

namespace {
	Application* gGLApp = nullptr;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void resizingCallback(GLFWwindow* window, int newWidth, int newHeight);

Application::Application() {
	gGLApp = this;
}

Application::~Application() {
	glfwTerminate();
}

bool Application::initContext(void) {
	if (!glfwInit())
	{
		ERROR_LOG("GLFW initialization failed.");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

#ifdef __APPLE__ 
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_FORWARD_COMPAT);
#endif

	GLFWmonitor* glfwMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* glfwMode = glfwGetVideoMode(glfwMonitor);

	glfwWindowHint(GLFW_RED_BITS, glfwMode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, glfwMode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, glfwMode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, glfwMode->refreshRate);
	//glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);

	clientWidth  = glfwMode->width;
	clientHeight = glfwMode->height;

	window = glfwCreateWindow(clientWidth, clientHeight, "Deformable Snow Simulation", glfwMonitor, nullptr);

	if (!window)
	{
		glfwTerminate();
		ERROR_LOG("GLFW Window Creating failed.");
		return false;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		ERROR_LOG("GLAD loading opengl functions failed.");
		return false;
	}

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);

	INFO_LOG("Vendor : {:<15}, Renderer : {:<15}", vendor, renderer);

	return true;
}

void Application::registerCallback(void) {
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseBtnCallback);
	glfwSetCursorPosCallback(window, mousePosCallback);
	glfwSetFramebufferSizeCallback(window, resizingCallback);
	glfwSetScrollCallback(window, scrollCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

}
void mousePosCallback(GLFWwindow* window, double xpos, double ypos) {

}
void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods) {

}
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {

}
void resizingCallback(GLFWwindow* window, int newWidth, int newHeight) {

}