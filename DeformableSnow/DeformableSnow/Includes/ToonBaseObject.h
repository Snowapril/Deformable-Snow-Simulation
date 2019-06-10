#ifndef TOON_BASE_OBJECT_H
#define TOON_BASE_OBJECT_H

namespace Toon
{
	class BaseObject
	{
	public:
		BaseObject() = default;
		virtual ~BaseObject() = 0;

		virtual bool init() noexcept = 0;
		virtual void release() noexcept = 0;
		virtual void bind() const noexcept = 0;
		virtual void unbind() const noexcept = 0;
		virtual void bindToGPU(bool deleteAfterPush = false) noexcept = 0;
	protected:
		unsigned int objectID { 0U };
	};
};

#endif