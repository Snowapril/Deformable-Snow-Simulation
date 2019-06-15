#ifndef TOON_INDEX_BUFFER_OBJECT_H
#define TOON_INDEX_BUFFER_OBJECT_H

#include "ToonBaseObject.h"
#include "ToonFormat.h"
#include "ToonPrerequisites.h"
#include "ToonPlatform.h"

#include <vector>
#include <memory>

namespace Toon
{
	class IndexBufferObject : public BaseObject
	{
		using super_t = BaseObject;
	public:
		IndexBufferObject() = default;
		IndexBufferObject(std::shared_ptr<ArrayObject>) noexcept;
		IndexBufferObject(IndexBufferObject const&) noexcept;
		IndexBufferObject& operator=(IndexBufferObject const&) noexcept;
		IndexBufferObject(IndexBufferObject&&) noexcept;
		IndexBufferObject& operator=(IndexBufferObject&&) noexcept;
		~IndexBufferObject() noexcept;

		bool init() noexcept override;
		void release() noexcept override;
		void bind() const noexcept override;
		void unbind() const noexcept override;
		void bindToGPU(bool _deleteAfterPush = false) noexcept override;
	public:
		void setIndicesPointer(void* _data, unsigned int _numIndices) noexcept;
		TOON_FORCE_INLINE std::shared_ptr<ArrayObject> getVertexArrayObject() const noexcept
		{
			return vaoPtr;
		}
		TOON_FORCE_INLINE unsigned int getNumberOfIndices() const noexcept
		{
			return numberOfIndices;
		}
	private:
		void* data = nullptr; // first 8byte is long long data for representing data total size.
		std::shared_ptr< ArrayObject > vaoPtr = nullptr;
		unsigned int numberOfIndices = 0U;
	};
};

#endif