#include "stdafx.h"
#include "ToonStaticCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Toon
{
	/****************************************************************************
							Camera class  definition
	****************************************************************************/
	StaticCamera::StaticCamera(glm::vec3 const& _position, glm::vec3 const& _direction) noexcept
		: position(_position), direction(_direction)
	{
	}

	StaticCamera::StaticCamera(StaticCamera const & other) noexcept
		: viewMatrix(other.viewMatrix), projectionMatrix(other.projectionMatrix), position(other.position), direction(other.direction)
	{
	}

	StaticCamera::StaticCamera(StaticCamera&& other) noexcept
		: viewMatrix(std::move(other.viewMatrix)), projectionMatrix(std::move(other.projectionMatrix)), position(std::move(other.position)), direction(std::move(other.direction))
	{
	}

	StaticCamera& StaticCamera::operator=(StaticCamera const & other) noexcept
	{
		if ( &other != this )
		{
			viewMatrix		 = other.viewMatrix;
			projectionMatrix = other.projectionMatrix;
			position		 = other.position;
			direction		 = other.direction;
		}

		return *this;
	}

	StaticCamera& StaticCamera::operator=(StaticCamera&& other) noexcept
	{
		if ( &other != this )
		{
			viewMatrix		 = std::move(other.viewMatrix);
			projectionMatrix = std::move(other.projectionMatrix);
			position		 = std::move(other.position);
			direction		 = std::move(other.direction);
		}

		return *this;
	}

	void StaticCamera::setViewMatrix(glm::vec3 const& _up) noexcept
	{
		viewMatrix = glm::lookAt(position, position + direction, _up);
	}
	void StaticCamera::setOrthogonalMatrix(glm::vec3 const& _left, glm::vec3 const& _right, glm::vec3 const& _top, glm::vec3 const& _bottom) noexcept
	{
		projectionMatrix = glm::ortho(_left, _right, _top, _bottom);
	}
	void StaticCamera::setPerspectiveMatrix(float _fov, float _aspect, float _zNear, float _zFar) noexcept
	{
		projectionMatrix = glm::perspective(glm::radians(_fov), _aspect, _zNear, _zFar);
	}
};