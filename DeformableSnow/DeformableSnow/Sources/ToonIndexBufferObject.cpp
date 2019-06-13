#include "stdafx.h"
#include "ToonIndexBufferObject.h"

#include <glew/glew.h>

namespace Toon
{
	IndexBufferObject::IndexBufferObject(IndexBufferObject const&) noexcept
	{
	}

	IndexBufferObject& IndexBufferObject::operator=(IndexBufferObject const&) noexcept
	{
		return *this;
	}

	IndexBufferObject::IndexBufferObject(IndexBufferObject&&) noexcept
	{
	}

	IndexBufferObject& IndexBufferObject::operator=(IndexBufferObject&&) noexcept
	{
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

	void IndexBufferObject::setIndicesPointer(void* _data) noexcept
	{
		data = _data;
	}
};