#ifndef TOON_STATIC_CAMERA_H
#define TOON_STATIC_CAMERA_H

#include "ToonPlatform.h"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace Toon
{
	/****************************************************************************
							Camera class declaration
	****************************************************************************/
	class StaticCamera
	{
	public:
		StaticCamera() = default;
		StaticCamera(glm::vec3 const&, glm::vec3 const&) noexcept;
		StaticCamera(StaticCamera const &) noexcept;
		StaticCamera& operator=(StaticCamera const&) noexcept;
		StaticCamera(StaticCamera&&) noexcept;
		StaticCamera& operator=(StaticCamera&&) noexcept;

	public:	
		void setViewMatrix(glm::vec3 const& _up) noexcept;
		void setOrthogonalMatrix(glm::vec3 const& _left, glm::vec3 const& _right, glm::vec3 const& _top, glm::vec3 const& _bottom) noexcept;
		void setPerspectiveMatrix(float _fov, float _aspect, float _zNear, float _zFar) noexcept;

		TOON_FORCE_INLINE glm::mat4 const& getView() const noexcept
		{
			return viewMatrix;
		}
		TOON_FORCE_INLINE glm::mat4 const& getProjection() const noexcept
		{
			return projectionMatrix;
		}
		TOON_FORCE_INLINE glm::vec3 const& getPosition() const noexcept
		{
			return position;
		}
		TOON_FORCE_INLINE glm::vec3 const& getDirection() const noexcept
		{
			return direction;
		}
	private:
		glm::mat4	viewMatrix{};
		glm::mat4	projectionMatrix{};
		glm::vec3	position{};
		glm::vec3	direction{};
	};
};

#endif