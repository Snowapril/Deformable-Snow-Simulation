#include "stdafx.h"
#include "ToonMesh.h"

#include "ToonVertexBufferObject.h"
#include "ToonIndexBufferObject.h"
#include "ToonArrayObject.h"

#include <glew/glew.h>

namespace Toon
{
	Mesh::Mesh(Mesh const & other) noexcept
		: vboArray(other.vboArray), iboArray(other.iboArray)
	{
	}

	Mesh & Mesh::operator=(Mesh const & other) noexcept
	{
		if (&other != this)
		{
			vboArray = other.vboArray;
			iboArray = other.iboArray;
		}
		return *this;
	}

	Mesh::Mesh(Mesh&& other) noexcept
		: vboArray(std::move(other.vboArray)), iboArray(std::move(other.iboArray))
	{
	}

	Mesh& Mesh::operator=(Mesh&& other) noexcept
	{
		if (&other != this)
		{
			vboArray = std::move(other.vboArray);
			iboArray = std::move(other.iboArray);
		}
		return *this;
	}

	Mesh::~Mesh() noexcept
	{
		vboArray.clear();
		iboArray.clear();
	}

	void Mesh::render(PrimitiveFormat _primitiveFormat) const noexcept
	{
		for (auto const& vbo : vboArray)
		{
			vbo->getVertexArrayObject()->bind();
			glDrawArrays(_primitiveFormat.mode, 0, vbo->getNumberOfVertices());
		}
	}

	void Mesh::renderIndexed(PrimitiveFormat _primitiveFormat) const noexcept
	{
		for (auto const& ibo : iboArray)
		{
			ibo->getVertexArrayObject()->bind();
			glDrawElements(_primitiveFormat.mode, ibo->getNumberOfIndices(), GL_UNSIGNED_INT, nullptr);
		}
	}

	void Mesh::addVertexBufferObject(std::shared_ptr< VertexBufferObject > _bufferPtr) noexcept
	{
		vboArray.push_back(_bufferPtr);
	}
	void Mesh::addIndexBufferObject(std::shared_ptr< IndexBufferObject > _bufferPtr) noexcept
	{
		iboArray.push_back(_bufferPtr);
	}
};