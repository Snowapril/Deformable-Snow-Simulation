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

#define		TOON_KEY_COUNT 349

#define 	TOON_KEY_UNKNOWN   -1
#define 	TOON_KEY_SPACE   32
#define 	TOON_KEY_APOSTROPHE   39 /* ' */
#define 	TOON_KEY_COMMA   44 /* , */
#define 	TOON_KEY_MINUS   45 /* - */
#define 	TOON_KEY_PERIOD   46 /* . */
#define 	TOON_KEY_SLASH   47 /* / */
#define 	TOON_KEY_0   48
#define 	TOON_KEY_1   49
#define 	TOON_KEY_2   50
#define 	TOON_KEY_3   51
#define 	TOON_KEY_4   52
#define 	TOON_KEY_5   53
#define 	TOON_KEY_6   54
#define 	TOON_KEY_7   55
#define 	TOON_KEY_8   56
#define 	TOON_KEY_9   57
#define 	TOON_KEY_SEMICOLON   59 /* ; */
#define 	TOON_KEY_EQUAL   61 /* = */
#define 	TOON_KEY_A   65
#define 	TOON_KEY_B   66
#define 	TOON_KEY_C   67
#define 	TOON_KEY_D   68
#define 	TOON_KEY_E   69
#define 	TOON_KEY_F   70
#define 	TOON_KEY_G   71
#define 	TOON_KEY_H   72
#define 	TOON_KEY_I   73
#define 	TOON_KEY_J   74
#define 	TOON_KEY_K   75
#define 	TOON_KEY_L   76
#define 	TOON_KEY_M   77
#define 	TOON_KEY_N   78
#define 	TOON_KEY_O   79
#define 	TOON_KEY_P   80
#define 	TOON_KEY_Q   81
#define 	TOON_KEY_R   82
#define 	TOON_KEY_S   83
#define 	TOON_KEY_T   84
#define 	TOON_KEY_U   85
#define 	TOON_KEY_V   86
#define 	TOON_KEY_W   87
#define 	TOON_KEY_X   88
#define 	TOON_KEY_Y   89
#define 	TOON_KEY_Z   90
#define 	TOON_KEY_LEFT_BRACKET   91 /* [ */
#define 	TOON_KEY_BACKSLASH   92 /* \ */
#define 	TOON_KEY_RIGHT_BRACKET   93 /* ] */
#define 	TOON_KEY_GRAVE_ACCENT   96 /* ` */
#define 	TOON_KEY_WORLD_1   161 /* non-US #1 */
#define 	TOON_KEY_WORLD_2   162 /* non-US #2 */
#define 	TOON_KEY_ESCAPE   256
#define 	TOON_KEY_ENTER   257
#define 	TOON_KEY_TAB   258
#define 	TOON_KEY_BACKSPACE   259
#define 	TOON_KEY_INSERT   260
#define 	TOON_KEY_DELETE   261
#define 	TOON_KEY_RIGHT   262
#define 	TOON_KEY_LEFT   263
#define 	TOON_KEY_DOWN   264
#define 	TOON_KEY_UP   265
#define 	TOON_KEY_PAGE_UP   266
#define 	TOON_KEY_PAGE_DOWN   267
#define 	TOON_KEY_HOME   268
#define 	TOON_KEY_END   269
#define 	TOON_KEY_CAPS_LOCK   280
#define 	TOON_KEY_SCROLL_LOCK   281
#define 	TOON_KEY_NUM_LOCK   282
#define 	TOON_KEY_PRINT_SCREEN   283
#define 	TOON_KEY_PAUSE   284
#define 	TOON_KEY_F1   290
#define 	TOON_KEY_F2   291
#define 	TOON_KEY_F3   292
#define 	TOON_KEY_F4   293
#define 	TOON_KEY_F5   294
#define 	TOON_KEY_F6   295
#define 	TOON_KEY_F7   296
#define 	TOON_KEY_F8   297
#define 	TOON_KEY_F9   298
#define 	TOON_KEY_F10   299
#define 	TOON_KEY_F11   300
#define 	TOON_KEY_F12   301
#define 	TOON_KEY_F13   302
#define 	TOON_KEY_F14   303
#define 	TOON_KEY_F15   304
#define 	TOON_KEY_F16   305
#define 	TOON_KEY_F17   306
#define 	TOON_KEY_F18   307
#define 	TOON_KEY_F19   308
#define 	TOON_KEY_F20   309
#define 	TOON_KEY_F21   310
#define 	TOON_KEY_F22   311
#define 	TOON_KEY_F23   312
#define 	TOON_KEY_F24   313
#define 	TOON_KEY_F25   314
#define 	TOON_KEY_KP_0   320
#define 	TOON_KEY_KP_1   321
#define 	TOON_KEY_KP_2   322
#define 	TOON_KEY_KP_3   323
#define 	TOON_KEY_KP_4   324
#define 	TOON_KEY_KP_5   325
#define 	TOON_KEY_KP_6   326
#define 	TOON_KEY_KP_7   327
#define 	TOON_KEY_KP_8   328
#define 	TOON_KEY_KP_9   329
#define 	TOON_KEY_KP_DECIMAL   330
#define 	TOON_KEY_KP_DIVIDE   331
#define 	TOON_KEY_KP_MULTIPLY   332
#define 	TOON_KEY_KP_SUBTRACT   333
#define 	TOON_KEY_KP_ADD   334
#define 	TOON_KEY_KP_ENTER   335
#define 	TOON_KEY_KP_EQUAL   336
#define 	TOON_KEY_LEFT_SHIFT   340
#define 	TOON_KEY_LEFT_CONTROL   341
#define 	TOON_KEY_LEFT_ALT   342
#define 	TOON_KEY_LEFT_SUPER   343
#define 	TOON_KEY_RIGHT_SHIFT   344
#define 	TOON_KEY_RIGHT_CONTROL   345
#define 	TOON_KEY_RIGHT_ALT   346
#define 	TOON_KEY_RIGHT_SUPER   347
#define 	TOON_KEY_MENU   348
#define 	TOON_KEY_LAST   TOON_KEY_MENU

#endif