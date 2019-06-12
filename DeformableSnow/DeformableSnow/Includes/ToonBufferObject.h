#ifndef TOON_BUFFER_OBJECT_H
#define TOON_BUFFER_OBJECT_H

#include "ToonBaseObject.h"
#include "ToonFormat.h"

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
		
	private:
		TOON_OBJECT_FORMAT bufferType;
	};
};

#endif