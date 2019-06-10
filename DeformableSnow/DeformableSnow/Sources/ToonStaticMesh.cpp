#include "stdafx.h"
#include "ToonStaticMesh.h"

#include <glew/glew.h>
namespace Toon
{
	StaticMesh::StaticMesh(void* _vertices, unsigned int _interpret_format) noexcept
	{
	}
	/****************************************************************************
						Mesh class  definition
	****************************************************************************/
	StaticMesh::StaticMesh(StaticMesh const & other)
	{
	}

	StaticMesh & StaticMesh::operator=(StaticMesh const & other)
	{
		return *this;
	}

	void StaticMesh::bindMesh(void) const noexcept
	{
		
	}
	void StaticMesh::unbindMesh(void) const noexcept
	{
	}
};