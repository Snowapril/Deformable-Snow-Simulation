#include "stdafx.h"
#include "ToonBufferObject.h"

#include <glew/glew.h>
#include <iostream>

namespace Toon
{
	BufferObject::BufferObject(TOON_OBJECT_FORMAT _buffer_type) noexcept
		: super_t()
	{
		setBufferType(_buffer_type);
	}

	BufferObject::BufferObject(BufferObject const& other) noexcept
	{

	}

	BufferObject& BufferObject::operator=(BufferObject const& other) noexcept
	{
		if (this != &other)
		{

		}

		return *this;
	}

	BufferObject::BufferObject(BufferObject&& other) noexcept
	{

	}

	BufferObject& BufferObject::operator=(BufferObject&& other) noexcept
	{
		if (this != &other)
		{

		}

		return *this;
	}

	BufferObject::~BufferObject() noexcept
	{
		release();
	}

	bool BufferObject::init() noexcept
	{
		glGenBuffers(1, &objectID);
	}

	void BufferObject::release() noexcept
	{
		if (objectID != 0U) glDeleteBuffers(1, &objectID);
	}

	void BufferObject::bind() const noexcept
	{
		glBindBuffer(bufferType, objectID);
	}

	void BufferObject::unbind() const noexcept
	{
		glBindBuffer(bufferType, 0U);
	}

	void BufferObject::bindToGPU(bool _deleteAfterPush = false) noexcept
	{
		this->bind();

		char* tempData = reinterpret_cast<char*>(this->data);
		char tempDataSize[8];
		for (int i = 0; i < 8; i++)
			tempDataSize[i] = *(tempData++);
		long long* dataSize = reinterpret_cast<long long*>(tempDataSize);
		void* verticesData = tempData;

		glBufferData(bufferType, *dataSize, verticesData, GL_STATIC_DRAW);
		for (auto const& attrib : vAttribArray)
		{
			glEnableVertexAttribArray(attrib.index);
			glVertexAttribPointer(attrib.index, attrib.size, attrib.type, attrib.bNormalized, attrib.stride, (void*)(attrib.offset));
		}
		this->unbind();

		if (_deleteAfterPush)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void BufferObject::setBufferType(TOON_OBJECT_FORMAT _buffer_type) noexcept
	{
		switch (_buffer_type)
		{
		case TOON_OBJECT_FORMAT::VERTEX_BUFFER_OBJECT:
			bufferType = GL_ARRAY_BUFFER;
			break;
		case TOON_OBJECT_FORMAT::INDEX_BUFFER_OBJECT:
			bufferType = GL_INDEX_ARRAY;
			break;
		default:
			bufferType = 0U;
			std::cerr << "[BufferObject] Unknown buffer type was given" << std::endl;
			break;
		}
	}

	std::shared_ptr<ArrayObject> BufferObject::getVertexArrayObject() const noexcept
	{
		return vaoPtr;
	}

	void BufferObject::addVertexAttrib(VertexAttrib const& _vAttrib) noexcept
	{
		vAttribArray.push_back(_vAttrib);
	}
};