#include "stdafx.h"
#include "ToonColor.h"

namespace Toon
{
	const Color Color::Red		= Color(1.0f, 0.0f, 0.0f, 1.0f);
	const Color Color::Green	= Color(0.0f, 1.0f, 0.0f, 1.0f);
	const Color Color::Blue		= Color(0.0f, 0.0f, 1.0f, 1.0f);
	const Color Color::Black	= Color(0.0f, 0.0f, 0.0f, 1.0f);
	const Color Color::White	= Color(1.0f, 1.0f, 1.0f, 1.0f);

	Color::Color(float r, float g, float b, float a) noexcept
		: data{ r, g, b, a }
	{

	}
}