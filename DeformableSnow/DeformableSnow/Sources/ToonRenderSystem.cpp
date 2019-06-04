#include "stdafx.h"

#include "ToonRenderSystem.h"
#include <glew/glew.h>
#include <GLFW/glfw3.h>

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#include <fmt/format.h>

#include "ToonLogger.h"
#include "ToonTimer.h"
#include "ToonFileSystem.h"
#include "ToonExceptions.h"

namespace Common
{
	template <> Toon::RenderSystem* Singleton<Toon::RenderSystem>::instance = nullptr;
}

namespace Toon
{
	/****************************************************************************
						RenderSystem class definition
	****************************************************************************/
	using namespace Common;
	using namespace ToonResourceParser;

	namespace {
		Toon::RenderSystem* gInstance = nullptr;
	}

	RenderSystem::RenderSystem()
	{
		gInstance = this;
	}

	RenderSystem::RenderSystem(std::string const& title, int width, int height, bool fullscreen) noexcept
	{
		assert(!initWindow(title, width, height, fullscreen));
		gInstance = this;
	}
	RenderSystem::~RenderSystem() noexcept
	{
		glfwTerminate();
		Logger::getConstInstance().infoMessage("[Singleton] {0:>40} ({1:p})", "Rendersystem instance is released", reinterpret_cast<void*>(instance));
		gInstance = nullptr;
	}
	GLFWwindow const* RenderSystem::getWindow(void) const noexcept
	{
		return window;
	}
	double RenderSystem::getAspectRatio(void) const noexcept
	{
		return static_cast<double>(clientWidth) / clientHeight;
	}
	std::optional<std::string> RenderSystem::initWindow(std::string const& title, int width, int height, bool fullscreen) noexcept
	{
		if (!glfwInit())
		{
			glfwTerminate();
			return "GLFW initialization failed.";
		}

		this->wndCaption = title;
		this->clientWidth = width;
		this->clientHeight = height;
		this->bFullscreen = fullscreen;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ 
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_FORWARD_COMPAT);
#endif

		GLFWmonitor* glfwMonitor = glfwGetPrimaryMonitor();
		GLFWvidmode const* glfwMode = glfwGetVideoMode(glfwMonitor);

		glfwWindowHint(GLFW_RED_BITS, glfwMode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, glfwMode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, glfwMode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, glfwMode->refreshRate);
		glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);

		if (fullscreen)
		{
			clientWidth = glfwMode->width;
			clientHeight = glfwMode->height;
		}
		else
		{
			glfwMonitor = nullptr;
		}

		window = glfwCreateWindow(clientWidth, clientHeight, title.c_str(), glfwMonitor, nullptr);

		if (!window)
		{
			glfwTerminate();
			return "GLFW Window Creating failed.";
		}

		glfwMakeContextCurrent(window);

		glfwSetKeyCallback(window, keyCallback);
		glfwSetMouseButtonCallback(window, mouseBtnCallback);
		glfwSetFramebufferSizeCallback(window, resizingCallback);
		glfwSetCursorPosCallback(window, mousePosCallback);
		glfwSetScrollCallback(window, scrollCallback);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		int e = glewInit();
		if (e != GLEW_OK)
		{
			glfwTerminate();
			return fmt::format("GLEW Error occurred {}", glewGetErrorString(e));
		}

#define CHECK_EXTENSION(ext) if(!glewGetExtension("GL_ARB_"#ext)){ glfwTerminate();return fmt::format( "GLEW: GL_ARB_{} not supported.\n", #ext ); }
		CHECK_EXTENSION(shading_language_100);	// check your platform supports GLSL
		CHECK_EXTENSION(vertex_buffer_object);	// BindBuffers, DeleteBuffers, GenBuffers, IsBuffer, BufferData, BufferSubData, GenBufferSubData, ...
		CHECK_EXTENSION(vertex_shader);			// functions related to vertex shaders
		CHECK_EXTENSION(fragment_shader);			// functions related to fragment shaders
		CHECK_EXTENSION(shader_objects);			// functions related to program and shaders
#undef CHECK_EXTENSION

		return {};
	}

	auto RenderSystem::getVendorString(void) const noexcept
	{
		return glGetString(GL_VENDOR);
	}
	auto RenderSystem::getRendererString(void) const noexcept
	{
		return glGetString(GL_RENDERER);
	}
	void RenderSystem::preDrawScene(void) const noexcept
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 0.0, 0.0, 1.0);
	}
	void RenderSystem::drawScene(void) const noexcept
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	bool RenderSystem::getWindowShouldClose(void) const noexcept
	{
		return glfwWindowShouldClose(window);
	}

	bool RenderSystem::initFromConfigFile(INIParser const& parser) noexcept
	{
		auto width = parser.getData<int>("RenderSystem.client_width");
		auto height = parser.getData<int>("RenderSystem.client_height");
		auto title = parser.getData<std::string>("RenderSystem.window_title");
		auto fullscreen = parser.getData<bool>("RenderSystem.default_fullscreen");

		if (AnyOf(!width, !height, !title, !fullscreen))
		{
			Logger::getConstInstance().errorMessage("[RenderSystem] Resource Parsing Error Occurred.");
			return false;
		}

		auto initResult = initWindow(title.value(), width.value(), height.value(), fullscreen.value());
		if (initResult)
		{
			Logger::getConstInstance().errorMessage("[RenderSystem] Initialization error occurred. {0}", initResult.value());
			return false;
		}

		return true;
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	void mousePosCallback(GLFWwindow * window, double xpos, double ypos)
	{

	}
	void mouseBtnCallback(GLFWwindow * window, int btn, int action, int mods)
	{

	}
	void scrollCallback(GLFWwindow * window, double xoffset, double yoffset)
	{

	}
	void resizingCallback(GLFWwindow * window, int newWidth, int newHeight)
	{

	}
};