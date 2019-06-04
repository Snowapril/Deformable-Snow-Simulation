#pragma once

// because of compatibility issue, declare below macro for using std::allocator instead of std::pmr::memory_resource
// if there are improvements on std::pmr compatibility issue, toon engine codes will be refactored.
#define _SILENCE_STDEXT_ALLOCATORS_DEPRECATION_WARNING

#ifdef _DEBUG
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl/glfx.lib")
#pragma comment(lib, "opengl/glew32.lib")
#pragma comment(lib, "fmt/fmtd.lib")
#else
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl/glfx.lib")
#pragma comment(lib, "opengl/glew32.lib")
#pragma comment(lib, "fmt/fmt.lib")
#endif

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#include <Windows.h>
#pragma comment(lib, "opengl/glfw3.lib")
#elif
#pragma comment(lib, "opengl/glfw3.lib")
#endif