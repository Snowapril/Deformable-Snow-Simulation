/**
 * @file ToonSingleton.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief Provide singleton interface which enable smart global variable.
 * @version 0.1
 * @date 2019-05-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_SINGLETON_H
#define TOON_SINGLETON_H

// referencing on Ogre engine

#include "ToonNoncopyable.h"
#include <cassert>

namespace Common
{
	/****************************************************************************
						Singleton class declaration
	****************************************************************************/
	
	/**
	 * @brief singleton interface which enable smart global variable.
	 * 
	 * Below example is how to make user-custom class to singleton class.
	 * \code{.cpp}
	 * class Apple : public Singleton
	 * {
	 * public:
	 *     void balk(void) const { std::cout << "Assak!!" << std::endl; }
	 * }
	 * // in definition file, locate below code at the top of the file.
	 * template<> Apple* Singleton<Apple>::instance = nullptr;
	 * \endcode
	 * 
	 * @tparam Type custom class type that user want to make to singleton.
	 */
	template <typename Type>
	class Singleton : public Noncopyable
	{
	protected:
		static Type * instance;
	public:
		/**
		 * @brief Get the Const Instance object
		 * 
		 * @return Type const& 
		 */
		static Type const& getConstInstance (void)
		{
			assert(instance != nullptr);
			return *instance;
		}
		/**
		 * @brief Get the Mutable Instance object
		 * 
		 * @return Type& 
		 */
		static Type& getMutableInstance(void)
		{
			assert(instance != nullptr);
			return *instance;
		}
		/**
		 * @brief whether the singleton with the type is destroyed or not.
		 *  
		 * @return true  if the singleton with the type is destroyed.
		 * @return false if the singleton with the type valid.
		 */
		static bool	isDestroyed(void)
		{ 
			return instance == nullptr;
		}
	public:
		/**
		 * @brief Construct a new Singleton object
		 * When user call this constructor somewhere, before that instance is destroyed, user can make use of the instance at any-place.
		 */
		Singleton()
		{
			assert(instance == nullptr);
			instance = static_cast<Type*>(this);
		}
		/**
		 * @brief Destroy the Singleton object
		 * 
		 */
		virtual ~Singleton()
		{
			assert(instance != nullptr);
			instance = nullptr;
		}
	};
};

#endif //TOON_SINGLETON_HPP