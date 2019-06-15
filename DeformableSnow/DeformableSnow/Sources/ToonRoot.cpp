#include "stdafx.h"
#include "ToonRoot.h"

#include "ToonTimer.h"
#include "ToonRenderSystem.h"
#include "ToonExceptions.h"
#include "ToonRenderSystem.h"
#include "ToonArrayObject.h"

#include <algorithm>

namespace Toon
{
	/****************************************************************************
				ToonRoot class definition
	****************************************************************************/
	using namespace ToonResourceParser;

	ToonRoot::~ToonRoot()
	{
		snowShader.release();
		bufferState->release();
		bufferState.reset();
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
		deformableSnow.preDrawScene();

		super_t::preDrawScene();
	}

	void ToonRoot::drawScene(void) const noexcept
	{
		// here
		deformableSnow.drawScene();

		super_t::drawScene();
	}

	bool ToonRoot::initSceneObjects() noexcept
	{
		snowShader.init();
		snowShader.compileProgram("Shaders/snow.fx");

		bufferState = std::make_shared<ArrayObject>();
		bufferState->init();

		mainCam.setTransformation(glm::vec3(1.0f, 1.0f, 1.0f), glm::normalize(-glm::vec3(1.0f, 1.0f, 1.0f)));
		mainCam.setViewMatrix(glm::vec3(0.0f, 1.0f, 0.0f));
		mainCam.setPerspectiveMatrix(45.0f, static_cast<float>(clientWidth) / clientHeight, 0.1f, 500.0f);

		deformableSnow.resetTerrain(bufferState, 5);

		timer.reset();

		return true;
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