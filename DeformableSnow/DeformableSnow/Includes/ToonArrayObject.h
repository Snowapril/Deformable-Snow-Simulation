#ifndef TOON_ARRAY_OBJECT_H
#define TOON_ARRAY_OBJECT_H

#include "ToonBaseObject.h"

namespace Toon
{
	class ArrayObject : public BaseObject
	{
		using super_t = BaseObject;
	public:
		ArrayObject() = default;
		ArrayObject(ArrayObject const&) noexcept;
		ArrayObject& operator=(ArrayObject const&) noexcept;
		ArrayObject(ArrayObject&&) noexcept;
		ArrayObject& operator=(ArrayObject&&) noexcept;
		~ArrayObject() noexcept;

		bool init() noexcept override;
		void release() noexcept override;
		void bind() const noexcept override;
		void unbind() const noexcept override;
		void bindToGPU(bool _deleteAfterPush = false) noexcept override;
	};
};

#endif