/**
 * @file ToonRenderSystem.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief toon engien render system which inherit other specific render system such as opengl, vulkan and directx. at now, inherits opengl render system.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_RENDERSYSTEM_H
#define TOON_RENDERSYSTEM_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include <string>
#include <INIParser.h>
#include "ToonSingleton.h"
struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
						RenderSystem class declaration
	****************************************************************************/
	class RenderSystem : public Common::Singleton<RenderSystem>
	{
	public:
		RenderSystem() = default;
		RenderSystem(std::string const& title, int width, int height, bool fullscreen = false) noexcept;
		~RenderSystem() noexcept;

		GLFWwindow const* getWindow(void) const noexcept;
		double getAspectRatio(void) const noexcept;

		// Opengl window and context initialization.
		// note : if this return {}, it means initialization was successful.
		std::optional<std::string> initWindow(std::string const& title, int width, int height, bool fullscreen = false) noexcept;
		bool initFromConfigFile(ToonResourceParser::INIParser const&) noexcept;
		unsigned char const* getVendorString(void) const noexcept;
		unsigned char const* getRendererString(void) const noexcept;
		bool getWindowShouldClose(void) const noexcept;
	public:
		bool initialUpdate(void) noexcept;
		void preDrawScene(void) const noexcept;
		void drawScene(void) const noexcept;
	protected:
		std::string wndCaption{};
		GLFWwindow* window = nullptr;

		int clientWidth{ 0 };
		int clientHeight{ 0 };
		bool bFullscreen{ false };
		bool bUseGUI{ false };
	};
};


#include "ToonHeaderPostfix.h"

#endif