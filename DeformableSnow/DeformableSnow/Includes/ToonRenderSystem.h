#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include <string>
#include <INIParser.h>
struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
						RenderSystem class declaration
	****************************************************************************/
	class RenderSystem
	{
	public:
		RenderSystem();
		RenderSystem(std::string const& title, int width, int height, bool fullscreen = false) noexcept;
		virtual ~RenderSystem() noexcept;

		GLFWwindow const* getWindow(void) const noexcept;
		double getAspectRatio(void) const noexcept;

		// Opengl window and context initialization.
		// note : if this return {}, it means initialization was successful.
		std::optional<std::string> initWindow(std::string const& title, int width, int height, bool fullscreen = false) noexcept;
		bool initFromConfigFile(ToonResourceParser::INIParser const&) noexcept;
		unsigned char const* getVendorString(void) const noexcept;
		unsigned char const* getRendererString(void) const noexcept;
		bool getWindowShouldClose(void) const noexcept;
		void setWindowShouldClose(void) noexcept;
	public:
		virtual void preDrawScene(void) const noexcept;
		virtual void drawScene(void) const noexcept;

		virtual void processKeyCallback(int key, int scancode, int action, int mode) noexcept = 0;
		virtual void processMousePosCallback(double xpos, double ypos) noexcept = 0;
		virtual void processMouseBtnCallback(int btn, int action, int mods) noexcept = 0;
		virtual void processScrollCallback(double xoffset, double yoffset) noexcept = 0;
		virtual void processResizingCallback(int newWidth, int newHeight) noexcept = 0;
	protected:
		std::string wndCaption{};
		GLFWwindow* window = nullptr;

		int clientWidth{ 0 };
		int clientHeight{ 0 };
		bool bFullscreen{ false };
	};
};


#include "ToonHeaderPostfix.h"

#endif