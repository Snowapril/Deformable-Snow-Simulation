#ifndef TOON_OBJECT_H
#define TOON_OBJECT_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include <memory>

namespace Toon
{
	class Object
	{
	public:
		Object() = default;
		Object(Object const&) noexcept;
		Object& operator=(Object const&) noexcept;
		Object(Object&&) noexcept;
		Object& operator=(Object&&) noexcept;
		~Object() noexcept;
	private:
		std::shared_ptr<Mesh>		meshPtr		= nullptr;
		std::shared_ptr<Material>	materialPtr = nullptr;
	};
};

#include "ToonHeaderPostfix.h"
#endif