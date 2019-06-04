/**
 * @file ToonPlatform.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide platform specific macros and functions.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_PLATFORM_H
#define TOON_PLATFORM_H

#define TOON_SIMD_ALLIGNMENT 16

#if _MSC_VER >= 1900 
#define TOON_FORCE_INLINE __forceinline
#elif _GNUC_ 
#define TOON_FORCE_INLINE __attribute__((always_inline))
#endif

#define TOON_KEY_COUNT 349

#ifdef _WIN32
#include <Windows.h>
TOON_FORCE_INLINE void SleepCrossPlatform(unsigned long ms) noexcept
{
	Sleep(ms);
}
#elif __linux__
#include <unistd.h>
TOON_FORCE_INLINE void SleepCrossPlatform(unsigned long ms) noexcept
{
	unsigned long seconds = ms / static_cast<float>(1000);
	sleep(seconds);
}
#endif


#endif