#ifndef TOON_BASE_OBJECT_H
#define TOON_BASE_OBJECT_H

namespace Toon
{
	class BaseObject
	{
	public:
		BaseObject() = default;
		BaseObject(BaseObject const& other) noexcept
			: objectID(other.objectID) {};
		BaseObject& operator=(BaseObject const& other) noexcept
		{
			if (this != &other)
			{
				objectID = other.objectID;
			}
			return *this;
		}
		BaseObject(BaseObject&& other) noexcept
			: objectID(other.objectID) {};
		BaseObject& operator=(BaseObject&& other) noexcept
		{
			if (this != &other)
			{
				objectID = other.objectID;
				other.objectID = 0U;
			}
			return *this;
		}
		virtual ~BaseObject() noexcept {};

		virtual bool init() noexcept = 0;
		virtual void release() noexcept = 0;
		virtual void bind() const noexcept = 0;
		virtual void unbind() const noexcept = 0;
		virtual void bindToGPU(bool deleteAfterPush = false) noexcept = 0;

		inline unsigned int getObjectID() const noexcept
		{
			return objectID;
		}
	protected:
		unsigned int objectID { 0U };
	};
};

#endif