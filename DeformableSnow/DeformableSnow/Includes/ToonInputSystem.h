/**
 * @file ToonGL3PlusInputSystem.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief Provide useful input system methods which controlled by OpenGL3 Callback system.
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_INPUTSYSTEM_H
#define TOON_INPUTSYSTEM_H

#include <ToonSingleton.h>

#include "ToonPlatform.h"

namespace Toon
{
	/****************************************************************************
				InputSystem class declaration here
	****************************************************************************/
	class InputSystem : public Common::Singleton<InputSystem>
	{
	public:
		InputSystem() = default;
		~InputSystem() noexcept;
	public:
		void processKeyCallback(int key, int scancode, int action, int mode) noexcept; 
		void processMousePosCallback(double xpos, double ypos) noexcept;
		void processMouseBtnCallback(int btn, int action, int mods) noexcept;
		void processScrollCallback(double xoffset, double yoffset) noexcept;
		void processResizingCallback(int newWidth, int newHeight) noexcept;
	private:
		
	};
};


#endif