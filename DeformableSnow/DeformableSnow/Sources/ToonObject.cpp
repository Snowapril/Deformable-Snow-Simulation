#include "stdafx.h"
#include "ToonObject.h"

namespace Toon
{
	Object::Object(Object const& other) noexcept
		: meshPtr(other.meshPtr), materialPtr(other.materialPtr)
	{
	}

	Object& Object::operator=(Object const& other) noexcept
	{
		if (&other == this)
		{
			this->meshPtr		= other.meshPtr;
			this->materialPtr	= other.materialPtr;
		}

		return *this;
	}

	Object::Object(Object&& other) noexcept
		: meshPtr(std::move(other.meshPtr)), materialPtr(std::move(other.materialPtr))
	{
	}

	Object& Object::operator=(Object&& other) noexcept
	{
		if (&other == this)
		{
			this->meshPtr		= std::move(other.meshPtr);
			this->materialPtr	= std::move(other.materialPtr);
		}

		return *this;
	}

	Object::~Object() noexcept
	{
		this->meshPtr.reset();
		this->materialPtr.reset();
	}
};