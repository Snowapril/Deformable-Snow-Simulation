#ifndef TOON_COLOR_H
#define TOON_COLOR_H

#include "ToonHeaderPrefix.h"
namespace Toon
{
	struct Color
	{
		float data[4] {0.0f, };

		const static Color Red;
		const static Color Green;
		const static Color Blue;
		const static Color Black;
		const static Color White;

		Color() = default;
		Color(float, float, float, float) noexcept;
	};
};

#include "ToonHeaderPostfix.h"
#endif