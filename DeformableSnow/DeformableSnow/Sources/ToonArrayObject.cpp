#include "stdafx.h"
#include "ToonArrayObject.h"

#include <glew/glew.h>

namespace Toon
{
	ArrayObject::ArrayObject(ArrayObject const& other) noexcept
	{
	}
	ArrayObject& ArrayObject::operator=(ArrayObject const& other) noexcept
	{
	}
	ArrayObject::ArrayObject(ArrayObject&& other) noexcept
	{
	}
	ArrayObject& ArrayObject::operator=(ArrayObject&& other) noexcept
	{
	}
	ArrayObject::~ArrayObject() noexcept
	{
		release();
	}
	bool ArrayObject::init() noexcept
	{
		glGenVertexArrays(1, &(objectID));

		return true;
	}
	void ArrayObject::release() noexcept
	{
		if (objectID != 0U) glDeleteVertexArrays(1, &(objectID));
	}
	void ArrayObject::bind() const noexcept
	{
		glBindVertexArray(objectID);
	}
	void ArrayObject::unbind() const noexcept
	{
		glBindVertexArray(0U);
	}
	void ArrayObject::bindToGPU(bool _deleteAfterPush) noexcept
	{

	}
	
};