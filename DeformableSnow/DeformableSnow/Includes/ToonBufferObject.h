#ifndef TOON_BUFFER_OBJECT_H
#define TOON_BUFFER_OBJECT_H

#include "ToonBaseObject.h"
#include "ToonFormat.h"
#include "ToonPrerequisites.h"

#include <vector>

namespace Toon
{
	struct VertexAttrib
	{
		unsigned int offset;
		unsigned int index;
		int size;
		unsigned int type;
		int stride;
		bool bNormalized;

		VertexAttrib(unsigned int _index, int _size, unsigned int _type, bool _bNormalized, int _stride, unsigned int _offset)
			: index(_index), size(_size), type(_type), bNormalized(_bNormalized), stride(_stride), offset(_offset) {};
	};

	class BufferObject : public BaseObject
	{
		using super_t = BaseObject;
	public:
		BufferObject() = default;
		BufferObject(TOON_OBJECT_FORMAT _buffer_type) noexcept;
		BufferObject(BufferObject const&) noexcept;
		BufferObject& operator=(BufferObject const&) noexcept;
		BufferObject(BufferObject&&) noexcept;
		BufferObject& operator=(BufferObject&&) noexcept;
		~BufferObject() noexcept;

		bool init() noexcept override;
		void release() noexcept override;
		void bind() const noexcept override;
		void unbind() const noexcept override;
		void bindToGPU(bool _deleteAfterPush = false) noexcept override;
	public:
		void setBufferType(TOON_OBJECT_FORMAT _buffer_type) noexcept;
		void addVertexAttrib(VertexAttrib const& _vAttrib) noexcept;
		std::shared_ptr<ArrayObject> getVertexArrayObject() const noexcept;
		inline unsigned int getNumberOfData() const noexcept
		{
			return numberOfData;
		}
	private:
		void* data = nullptr; // first 8byte is long long data for representing data total size.
		std::vector< VertexAttrib > vAttribArray;
		std::shared_ptr< ArrayObject > vaoPtr;
		unsigned int numberOfData;
		unsigned int bufferType;
	};
};

#endif