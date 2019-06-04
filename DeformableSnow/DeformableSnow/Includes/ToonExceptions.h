/**
 * @file ToonExceptions.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide useful functions which can deal with assertion and exception.
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_EXCEPTIONS_H
#define TOON_EXCEPTIONS_H

#include "ToonHeaderPrefix.h"
#include "ToonPlatform.h"
#include "ToonLogger.h"
#include <cassert>
#include <string>

/****************************************************************************
				ToonAssertion functions here.
****************************************************************************/
namespace Toon
{
	/**
	 * @brief upgrade version of assert macro function.
	 * 
	 * @tparam Bits variadic template parameter for boolean parameter.
	 * @param msg  when assertion failed, this message will be printed.
	 * @param file file name where assertion failed.
	 * @param line source code line number where assertion failed.
	 * @param conditions variadic boolean parameters
	 */
	template <typename... Bits>
	TOON_FORCE_INLINE void _ToonAssert(char const* msg, char const* file, int line, Bits... conditions)
	{
		if (!(conditions && ...))
		{
			auto const & logger = Logger::getConstInstance();
			logger.errorMessage(msg);
			logger.errorMessage("At file ({0}) in line number ({1})", file, line);
			std::abort();
		}
	}

	/**
	 * @brief when any of variadic boolean parameters true, this function will return true.
	 * 
	 * @tparam Logics template variadic parameter of variadic boolean parameters.
	 * @param conditions variadic parameter for several boolean arguments. 
	 * @return any of boolean parameters is true, return true.
	 */
	template < typename... Logics >
	TOON_FORCE_INLINE bool AnyOf(Logics... conditions)
	{
		return ((conditions) || ...);
	}

	/**
	 * @brief when any of variadic boolean parameters false, this function will return false.
	 * 
	 * @tparam Logics template variadic parameter of variadic boolean parameters.
	 * @param conditions variadic parameter for several boolean arguments. 
	 * @return any of boolean parameters is false, return false.
	 */
	template < typename... Logics >
	TOON_FORCE_INLINE bool AllOf(Logics... conditions)
	{
		return ((conditions) && ...);
	}
};

#define	ToonAssert(msg, ...) Toon::_ToonAssert(msg, __FILE__, __LINE__, (##__VA_ARGS__))

#include "ToonHeaderPostfix.h"

#endif