#include "stdafx.h"
#include "ToonMesh.h"

#include "ToonBufferObject.h"
#include "ToonArrayObject.h"

#include <glew/glew.h>

namespace Toon
{
	Mesh::Mesh(Mesh const & other) noexcept
	{
	}

	Mesh & Mesh::operator=(Mesh const & other) noexcept
	{
		return *this;
	}

	Mesh::Mesh(Mesh&& other) noexcept
	{

	}

	Mesh& Mesh::operator=(Mesh&& other) noexcept
	{
		return *this;
	}

	Mesh::~Mesh() noexcept
	{
	}

	void Mesh::render(unsigned int _primitiveFormat) const noexcept
	{
		unsigned int previousID = 0U;
		for (auto bufferObj : bufferManageArray)
		{
			unsigned int currentID = bufferObj->getVertexArrayObject()->getObjectID();
			if (previousID != currentID)
			{
				bufferObj->bind();
				previousID = currentID;
			}
			glDrawElements(_primitiveFormat, buffer		)
		}
	}

	void Mesh::renderInstanced(unsigned int _primitiveFormat) const noexcept
	{

	}

	void Mesh::addBufferObject(std::shared_ptr<BufferObject> _bufferPtr) noexcept
	{
		bufferManageArray.push_back(_bufferPtr);
	}
};