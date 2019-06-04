/**
 * @file ToonBitwise.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief several inline functions for bitwise computation.
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_BITWISE_H
#define TOON_BITWISE_H

#include "ToonHeaderPrefix.h"
#include "ToonPlatform.h"
#include <cstddef>
#include <type_traits>

namespace Toon
{
	/****************************************************************************
				Bitwise class declaration
	****************************************************************************/
	class Bitwise
	{
	public:
		/**
		 * @brief return whether if given number is power of two or not.
		 * 
		 * @tparam Type the type of given unsigned number(char, short, int, long, etc..)
		 * @tparam std::enable_if_t< std::is_unsigned_v<Type>> disable this function if given type isn't a unsigned type.
		 * @param num unsigned number which programmer want to check if it is power of two.
		 * @return true  given number is power of two.
		 * @return false given number is not power of two.
		 */
		template <typename Type, typename = typename std::enable_if_t< std::is_unsigned_v<Type>> >
		static bool TOON_FORCE_INLINE isPO2(Type num)
		{
			return (num & (num - 1)) == 0;
		}

		/**
		 * @brief get bitmask with given indices easily
		 * 
		 * \code{.cpp}
		 * unsigned int mask = setBitmask<unsigned int>(0, 3, 7, 9); 
		 * std::cout << std::hex << mask << std::endl; 
		 * >> 0x0289 == 0000001010001001 
		 * \endcode
		 * 
		 * @tparam RetType 
		 * @tparam Bits variadic template parameter for enter the varying number of index.
		 * @tparam std::enable_if_t< std::is_integral_v<RetType>> 
		 * @param bits indices for set mask.
		 * @return std::decay_t<RetType> std::decay_t is used for the cast that programmer enter the return type as reference type by mistake.
		 */
		template < typename RetType, typename... Bits, typename = typename std::enable_if_t< std::is_integral_v<RetType>> >
		static auto TOON_FORCE_INLINE setBitmask(Bits... bits) -> std::decay_t<RetType>
		{
			RetType mask = ((1 << bits) | ...);
			return mask;
		}
	};
};

#include "ToonHeaderPrefix.h"

#endif