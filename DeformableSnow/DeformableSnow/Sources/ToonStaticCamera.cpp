#include "stdafx.h"
#include "ToonStaticCamera.h"

namespace Toon
{
	/****************************************************************************
							Camera class  definition
	****************************************************************************/
	StaticCamera::StaticCamera()
	{
	}

	StaticCamera::StaticCamera(StaticCamera const & other)
		: position(other.position), direction(other.direction)
	{
	}

	StaticCamera::StaticCamera(StaticCamera&& other)
		: position(std::move(other.position)), direction(std::move(other.direction))
	{
	}

	StaticCamera::~StaticCamera()
	{
	}

	StaticCamera& StaticCamera::operator=(StaticCamera const & other)
	{
		if ( &other != this )
		{
			position	= other.position	;
			direction	= other.direction	;
		}

		return *this;
	}

	StaticCamera& StaticCamera::operator=(StaticCamera&& other)
	{
		if ( &other != this )
		{
			position	= std::move(other.position)	;
			direction	= std::move(other.direction);
		}

		return *this;
	}
};