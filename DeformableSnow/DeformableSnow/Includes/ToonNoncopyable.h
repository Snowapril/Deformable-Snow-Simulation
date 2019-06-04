/**
 * @file ToonNoncopyable.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief Provide Noncopyable interface which make user-class to non-copyable class.
 * @version 0.1
 * @date 2019-05-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_NONCOPYABLE_H
#define TOON_NONCOPYABLE_H

namespace Common
{
	/****************************************************************************
							Noncopyable class declaration
	****************************************************************************/

	/**
	 * @brief Noncopyable interface which make user-class to non-copyable class.
	 * 
	 * If user want to make their class noncopyable, just inherits this interface.
	 * \code{.cpp}
	 * class Apple : public Noncopyable 
	 * {
	 *     Apple(int val) : value(val) {};
	 * private:
	 *     int value;
	 * };
	 * 
	 * Apple a(1), b(2);
	 * a = b; // this is not allowed.
	 * a = std::move(b) // also not allowed.
	 * \endcode
	 * 
	 */
	class Noncopyable
	{
	public:
		Noncopyable() = default;
		Noncopyable(Noncopyable const&) = delete;
		Noncopyable(Noncopyable&&	  ) = delete;
		Noncopyable& operator=(Noncopyable const&) = delete;
		Noncopyable& operator=(Noncopyable&&	 ) = delete;
	};
};

#endif //TOON_NONCOPYABLE_H