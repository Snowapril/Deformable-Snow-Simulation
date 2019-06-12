#include "stdafx.h"
#include "ToonMesh.h"

#include <glew/glew.h>
namespace Toon
{
	Mesh::Mesh(void* _vertices, TOON_MESH_FORMAT _interpret_format) noexcept
	{
	}

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

	Mesh& Mesh::operator=(Mesh&& other noexcept
	{

	}

	Mesh::~Mesh() noexcept
	{
		release();
	}

	bool Mesh::init() noexcept
	{

	}

	void Mesh::release() noexcept
	{

	}

	void Mesh::bind() const noexcept
	{

	}

	void Mesh::unbind() const noexcept
	{

	}

	void Mesh::bindToGPU(bool _deleteAfterPush = false) noexcept
	{

	}

};