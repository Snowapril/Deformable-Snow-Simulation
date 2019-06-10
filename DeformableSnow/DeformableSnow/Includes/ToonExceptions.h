#ifndef TOON_EXCEPTIONS_H
#define TOON_EXCEPTIONS_H

#include "ToonHeaderPrefix.h"
#include "ToonPlatform.h"
#include <cassert>
#include <string>

/****************************************************************************
				ToonAssertion functions here.
****************************************************************************/
namespace Toon
{
	template <typename... Bits>
	TOON_FORCE_INLINE void _ToonAssert(char const* msg, char const* file, int line, Bits... conditions)
	{
		if (!(conditions && ...))
		{
			std::cerr << msg << std::endl;
			std::cerr << "At file (" << file << ") in line number (" << line << ")" << std::endl;
			std::abort();
		}
	}

	template < typename... Logics >
	TOON_FORCE_INLINE bool AnyOf(Logics... conditions)
	{
		return ((conditions) || ...);
	}

	template < typename... Logics >
	TOON_FORCE_INLINE bool AllOf(Logics... conditions)
	{
		return ((conditions) && ...);
	}
};

#define	ToonAssert(msg, ...) Toon::_ToonAssert(msg, __FILE__, __LINE__, (##__VA_ARGS__))

#include "ToonHeaderPostfix.h"

#endif