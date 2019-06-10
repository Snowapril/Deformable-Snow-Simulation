#include "stdafx.h"
#include "ToonInputSystem.h"
#include "ToonLogger.h"
namespace Common
{
	template <> Toon::InputSystem* Singleton<Toon::InputSystem>::instance = nullptr;
}

namespace Toon
{
	using namespace Common;
	InputSystem::~InputSystem() noexcept
	{
		Logger::getConstInstance().infoMessage("[Singleton] {0:>40} ({1:p})", "InputSystem instance is released", reinterpret_cast<void*>(instance));
	}
	void InputSystem::processKeyCallback(int key, int scancode, int action, int mode) noexcept
	{
	}
	void InputSystem::processMousePosCallback(double xpos, double ypos) noexcept
	{
	}
	void InputSystem::processMouseBtnCallback(int btn, int action, int mods) noexcept
	{
	}
	void InputSystem::processScrollCallback(double xoffset, double yoffset) noexcept
	{
	}
	void InputSystem::processResizingCallback(int newWidth, int newHeight) noexcept
	{
	}
};