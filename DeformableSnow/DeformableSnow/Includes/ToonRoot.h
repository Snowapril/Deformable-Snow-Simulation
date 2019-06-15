#ifndef TOON_ROOT_H
#define TOON_ROOT_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include "ToonTimer.h"
#include "ToonRenderSystem.h"
#include "DeformableSnow.h"
#include "ToonStaticCamera.h"
#include "ToonEffect.h"

#include <string>
#include <memory>
#include <stack>

struct GLFWwindow;

namespace Toon
{
	class ToonRoot : public RenderSystem
	{
		using super_t = RenderSystem;
	protected:
		bool initialUpdate(void) noexcept;
		void preUpdateScene(float dt) noexcept;
		void updateScene(float dt) noexcept;
		void preDrawScene(void) const noexcept;
		void drawScene(void) const noexcept;
	public:
		void processKeyCallback(int key, int scancode, int action, int mode) noexcept override;
		void processMousePosCallback(double xpos, double ypos) noexcept override;
		void processMouseBtnCallback(int btn, int action, int mods) noexcept override;
		void processScrollCallback(double xoffset, double yoffset) noexcept override;
		void processResizingCallback(int newWidth, int newHeight) noexcept override;
	public:
		ToonRoot() = default;
		~ToonRoot() noexcept;

		bool initSceneObjects() noexcept;
		int  runMainLoop(void) noexcept;
	private:
		std::shared_ptr<ArrayObject> bufferState;
		DeformableSnow deformableSnow{};
		StaticCamera mainCam;
		Timer timer{};
		Effect snowShader{};
	};
};

#include "ToonHeaderPostfix.h"

#endif