#include "stdafx.h"
#include "ToonBufferObject.h"

namespace Toon
{
	BufferObject::BufferObject(TOON_OBJECT_FORMAT _buffer_type) noexcept
		: super_t(), bufferType(_buffer_type)
	{

	}

	BufferObject::BufferObject(BufferObject const&) noexcept
	{

	}

	BufferObject& BufferObject::operator=(BufferObject const&) noexcept
	{

	}

	BufferObject::BufferObject(BufferObject&&) noexcept
	{

	}

	BufferObject& BufferObject::operator=(BufferObject&&) noexcept
	{

	}

	BufferObject::~BufferObject() noexcept
	{

	}

	bool BufferObject::init() noexcept
	{

	}

	void BufferObject::release() noexcept
	{

	}

	void BufferObject::bind() const noexcept
	{

	}

	void BufferObject::unbind() const noexcept
	{

	}

	void BufferObject::bindToGPU(bool _deleteAfterPush = false) noexcept
	{

	}

	void BufferObject::setBufferType(TOON_OBJECT_FORMAT _buffer_type) noexcept
	{

	}

};