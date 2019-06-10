#ifndef TOON_SINGLETON_H
#define TOON_SINGLETON_H

// referencing on Ogre engine

#include "ToonNoncopyable.h"
#include <cassert>

namespace Toon
{
	template <typename Type>
	class Singleton : public Noncopyable
	{
	protected:
		static Type * instance;
	public:
		static Type const& getConstInstance (void)
		{
			assert(instance != nullptr);
			return *instance;
		}
		static Type& getMutableInstance(void)
		{
			assert(instance != nullptr);
			return *instance;
		}
		static bool	isDestroyed(void)
		{ 
			return instance == nullptr;
		}
	public:
		Singleton()
		{
			assert(instance == nullptr);
			instance = static_cast<Type*>(this);
		}
		virtual ~Singleton()
		{
			assert(instance != nullptr);
			instance = nullptr;
		}
	};
};

#endif //TOON_SINGLETON_HPP