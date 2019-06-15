#include "stdafx.h"
#include "ToonIndexBufferObject.h"

#include <glew/glew.h>

namespace Toon
{
	IndexBufferObject::IndexBufferObject(std::shared_ptr<ArrayObject> _vao) noexcept
		: vaoPtr(_vao)
	{
	}
	IndexBufferObject::IndexBufferObject(IndexBufferObject const& other) noexcept
		: super_t(other)
	{
	}

	IndexBufferObject& IndexBufferObject::operator=(IndexBufferObject const& other) noexcept
	{
		if (this != &other)
		{
			objectID = other.objectID;
		}

		return *this;
	}

	IndexBufferObject::IndexBufferObject(IndexBufferObject&& other) noexcept
		: super_t(std::move(other))
	{
	}

	IndexBufferObject& IndexBufferObject::operator=(IndexBufferObject&& other) noexcept
	{
		if (this != &other)
		{
			objectID = other.objectID;
			other.objectID = 0U;
		}

		return *this;
	}

	IndexBufferObject::~IndexBufferObject() noexcept
	{
		release();
	}

	bool IndexBufferObject::init() noexcept
	{
		glGenBuffers(1, &objectID);
		return true;
	}

	void IndexBufferObject::release() noexcept
	{
		if (objectID != 0U) glDeleteBuffers(1, &objectID);
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void IndexBufferObject::bind() const noexcept
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, objectID);
	}

	void IndexBufferObject::unbind() const noexcept
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0U);
	}

	void IndexBufferObject::bindToGPU(bool _deleteAfterPush) noexcept
	{
		this->bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, numberOfIndices * sizeof(unsigned int), data, GL_STATIC_DRAW);
		this->unbind();

		if (_deleteAfterPush)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void IndexBufferObject::setIndicesPointer(void* _data, unsigned int _numIndices) noexcept
	{
		this->data = new float[_numIndices];
		std::memcpy(this->data, 
					_data, 
					_numIndices * sizeof(unsigned int));
		numberOfIndices = _numIndices;
	}
};