#include "stdafx.h"
#include "ToonRoot.h"

#include "ToonTimer.h"
#include "ToonRenderSystem.h"
#include "ToonExceptions.h"
#include "ToonRenderSystem.h"

#include <algorithm>

namespace Toon
{
	/****************************************************************************
				ToonRoot class definition
	****************************************************************************/
	using namespace ToonResourceParser;

	ToonRoot::~ToonRoot()
	{
	}	

	bool ToonRoot::initialize(std::string const & configFilePath) noexcept
	{
		INIParser parser(configFilePath);

		if (!initSubsystems(parser))
			return false;

		return true;
	}

	bool ToonRoot::initSubsystems(INIParser const& parser) noexcept
	{
		auto rootPath = parser.getData<std::string>("Common.root_path");
		auto logPath  = parser.getData<std::string>("Common.log_path");

		if (AnyOf(!rootPath, !logPath)) return false;
		
		if (!super_t::initFromConfigFile(parser)) return false;

		return true;
	}

	bool ToonRoot::initialUpdate(void) noexcept
	{
		return true;
	}

	void ToonRoot::preUpdateScene(float dt) noexcept
	{
	}

	void ToonRoot::updateScene(float dt) noexcept
	{
	}

	void ToonRoot::preDrawScene(void) const noexcept
	{
		// here

		super_t::preDrawScene();
	}

	void ToonRoot::drawScene(void) const noexcept
	{
		// here

		super_t::drawScene();
	}

	int ToonRoot::runMainLoop(void) noexcept
	{
		timer.reset();
		if (initialUpdate() == false)
		{
			std::cerr << "[Root] Initial update was failed" << std::endl;
			return -1;
		}

		while (!super_t::getWindowShouldClose())
		{
			timer.tick();
			float dt = timer.getDeltaTime();
			float totalTime = timer.getTotalTime();

			if (timer.isPaused())
			{
				SleepCrossPlatform(100U);
			}
			else
			{
				preUpdateScene(dt); // 1) pre-simulation step
				updateScene(dt);    // 2) simulation	 step
				preDrawScene();	    // 3) pre-draw		 step
				drawScene();	    // 4) darw  		 step
			}
		}

		return 0;
	}

	void ToonRoot::processKeyCallback(int key, int scancode, int action, int mode) noexcept
	{
		if (key == TOON_KEY_ESCAPE && action == TOON_KEY_PRESS) setWindowShouldClose();
	}
	void ToonRoot::processMousePosCallback(double xpos, double ypos) noexcept
	{

	}
	void ToonRoot::processMouseBtnCallback(int btn, int action, int mods) noexcept
	{

	}
	void ToonRoot::processScrollCallback(double xoffset, double yoffset) noexcept
	{

	}
	void ToonRoot::processResizingCallback(int newWidth, int newHeight) noexcept
	{

	}
};