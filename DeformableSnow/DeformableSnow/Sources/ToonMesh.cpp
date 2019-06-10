#include "stdafx.h"
#include "ToonMesh.h"

#include <glew/glew.h>
namespace Toon
{
	Mesh::Mesh(void* _vertices, unsigned int _interpret_format) noexcept
	{
	}
	/****************************************************************************
						Mesh class  definition
	****************************************************************************/
	Mesh::Mesh(Mesh const & other)
	{
	}

	Mesh & Mesh::operator=(Mesh const & other)
	{
		return *this;
	}

	void Mesh::bindMesh(void) const noexcept
	{
		
	}
	void Mesh::unbindMesh(void) const noexcept
	{
	}
};