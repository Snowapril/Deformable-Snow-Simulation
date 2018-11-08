#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>

namespace Util {
	unsigned int CreateTexture2D(std::string path, bool gamma = false);
	bool PrintErrors(std::string location, std::string message);

	template <typename T>
	inline T clamp(T value, T begin, T end)
	{
		if (value < begin)
			return begin;
		else if (value > end)
			return end;
		else
			return value;
	}
	template <typename T>
	inline T fract(T value)
	{
		return value - static_cast<int>(value);
	}
	template <typename T>
	inline T interpolate(T v1, T v2, float ratio)
	{
		ratio = clamp(ratio, 0.0f, 1.0f);
		return v1 * (1.0f - ratio) + v2 * ratio;
	}
}

#ifdef _DEBUG
#define PRINT_ERRORS(message)  { return Util::PrintErrors(std::string(__FILE__) + std::string(__LINE__), (message)); }
#else
#define PRINT_ERRORS(message)
#endif

#endif //UTIL_HPP