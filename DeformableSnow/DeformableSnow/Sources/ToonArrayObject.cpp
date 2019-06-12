#include "stdafx.h"
#include "ToonArrayObject.h"

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
	}
	bool ArrayObject::init() noexcept
	{
		return false;
	}
	void ArrayObject::release() noexcept
	{
	}
	void ArrayObject::bind() const noexcept
	{
	}
	void ArrayObject::unbind() const noexcept
	{
	}
	void ArrayObject::bindToGPU(bool _deleteAfterPush) noexcept
	{
	}
};