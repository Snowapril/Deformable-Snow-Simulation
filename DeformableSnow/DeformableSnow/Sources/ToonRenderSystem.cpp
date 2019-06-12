#include "stdafx.h"

#include "ToonHeaderPrefix.h"
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#include <fmt/format.h>
#include <chrono>
#include <ctime>
#include <filesystem>
#include "ToonHeaderPostfix.h"

#include "ToonRenderSystem.h"
#include "ToonTimer.h"
#include "ToonExceptions.h"

using namespace ToonResourceParser;

namespace Toon
{
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mousePosCallback(GLFWwindow* window, double xpos, double ypos);
	void mouseBtnCallback(GLFWwindow* window, int btn, int action, int mods);
	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	void resizingCallback(GLFWwindow* window, int newWidth, int newHeight);

	namespace
	{
		RenderSystem* gInstance = nullptr;
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
		std::clog << "[RenderSystem] RenderSystem instance is released (" << std::hex << gInstance << ")" << std::endl;
		gInstance = nullptr;
		if (log.is_open())
		{
			auto now		= std::chrono::system_clock::now();
			auto nowTime	= std::chrono::system_clock::to_time_t(now);
			std::clog << "[RenderSystem] Simulation end at " << std::ctime(&nowTime) << std::endl;
			log.close();
		}
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

		// Set opengl version as 4.3 and use core profile (no legacy opengl)
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ 
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_FORWARD_COMPAT);
#endif

		// Set monitor advanced settings
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

		// Register callback functions to the current OpenGL context.
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
		CHECK_EXTENSION(fragment_shader);		// functions related to fragment shaders
		CHECK_EXTENSION(shader_objects);		// functions related to program and shaders
#undef CHECK_EXTENSION

		std::clog << "[RenderSystem] Vendor : " << getVendorString()   << std::endl;
		std::clog << "[RenderSystem] Renderer : " << getRendererString() << std::endl;

		return {}; // Initialization normally complete.
	}

	unsigned char const* RenderSystem::getVendorString(void) const noexcept
	{
		return glGetString(GL_VENDOR);
	}

	unsigned char const* RenderSystem::getRendererString(void) const noexcept
	{
		return glGetString(GL_RENDERER);
	}

	bool RenderSystem::getWindowShouldClose(void) const noexcept
	{
		return glfwWindowShouldClose(window);
	}

	void RenderSystem::setWindowShouldClose(void) noexcept
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	bool RenderSystem::initFromINIFile(std::string const& iniFilePath) noexcept
	{
		INIParser parser(iniFilePath);

		auto rootPath	= parser.getData<std::string>("Common.root_path");
		auto logPath	= parser.getData<std::string>("Common.log_path");
		auto width		= parser.getData<int>("RenderSystem.client_width");
		auto height		= parser.getData<int>("RenderSystem.client_height");
		auto title		= parser.getData<std::string>("RenderSystem.window_title");
		auto fullscreen = parser.getData<bool>("RenderSystem.default_fullscreen");

		if (AllOf(rootPath, logPath, width, height, title, fullscreen))
		{
			// connect clog and cerr stream to logging ofstream buffer.
			if (!setOutputStream(rootPath.value(), logPath.value()))
				return false;
			// initialize opengl window with config file values.
			auto initResult = initWindow(title.value(), width.value(), height.value(), fullscreen.value());
			// if boolean value of initResult is true, it means it have error message in the given optional instance.
			if (initResult)
			{
				std::cerr << "[RenderSystem] Initialization error occurred. " << initResult.value() << std::endl;
				return false;
			}
		}
		else
		{
			std::cerr << "[RenderSystem] Resource Parsing Error Occurred." << std::endl;
			return false;
		}

		return true;
	}

	bool RenderSystem::setOutputStream(std::string const& rootPath, std::string const& logPath) noexcept
	{
		namespace fs = std::filesystem;
		auto logDirectory = fs::path(rootPath + logPath);
		if (!fs::exists(logDirectory))
		{
			fs::create_directory(logDirectory);
		}

		if (log.is_open()) log.close();
		
		log.open(logDirectory.string() + std::string("/engine_log.log"), std::ofstream::out);
		if (log.is_open())
		{
			std::clog.rdbuf(log.rdbuf());
			std::cerr.rdbuf(log.rdbuf());
			auto now = std::chrono::system_clock::now();
			auto nowTime = std::chrono::system_clock::to_time_t(now);
			std::clog << "[RenderSystem] Simulation start at " << std::ctime(&nowTime) ;
		}
		else
		{
			std::cerr << "[RenderSystem] Create Logging file failed" << std::endl;
			return false;
		}

		return true;
	}

	void RenderSystem::preDrawScene(void) const noexcept
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 1.0);
	}

	void RenderSystem::drawScene(void) const noexcept
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		gInstance->processKeyCallback(key, scancode, action, mode);
	}

	void mousePosCallback(GLFWwindow * window, double xpos, double ypos)
	{
		gInstance->processMousePosCallback(xpos, ypos);
	}
	void mouseBtnCallback(GLFWwindow * window, int btn, int action, int mods)
	{
		gInstance->processMouseBtnCallback(btn, action, mods);
	}
	void scrollCallback(GLFWwindow * window, double xoffset, double yoffset)
	{
		gInstance->processScrollCallback(xoffset, yoffset);
	}
	void resizingCallback(GLFWwindow * window, int newWidth, int newHeight)
	{
		gInstance->processResizingCallback(newWidth, newHeight);
	}
};