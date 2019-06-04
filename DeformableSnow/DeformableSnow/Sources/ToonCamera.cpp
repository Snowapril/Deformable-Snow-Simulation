#include "stdafx.h"
#include "ToonCamera.h"

namespace Toon
{
	/****************************************************************************
							Camera class  definition
	****************************************************************************/
	Camera::Camera()
		: speed(0.0f)
	{
	}

	Camera::Camera(Camera const & other)
		: position(other.position), direction(other.direction), speed(other.speed)
	{
	}

	Camera::Camera(Camera && other)
		: position(std::move(other.position)), direction(std::move(other.direction)), speed(other.speed)
	{
	}

	Camera::~Camera()
	{
	}

	Camera & Camera::operator=(Camera const & other)
	{
		if ( &other != this )
		{
			position	= other.position	;
			direction	= other.direction	;
			speed		= other.speed		;
		}

		return *this;
	}

	Camera & Camera::operator=(Camera && other)
	{
		if ( &other != this )
		{
			position	= std::move(other.position)	;
			direction	= std::move(other.direction);
			speed		= other.speed;
		}

		return *this;
	}

	void Camera::processInput( int key, int button )
	{
	}
};