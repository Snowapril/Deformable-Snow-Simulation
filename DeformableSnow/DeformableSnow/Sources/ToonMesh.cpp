#include "stdafx.h"
#include "ToonMesh.h"

namespace Toon
{
	/****************************************************************************
						Mesh class  definition
	****************************************************************************/
	Mesh::Mesh(Mesh const & other)
		: positions(other.positions), normals(other.normals), uvs(other.uvs), indices(other.indices)
	{
	}

	Mesh & Mesh::operator=(Mesh const & other)
	{
		if (this != &other)
		{
			positions	= other.positions;
			normals		= other.normals;
			uvs			= other.uvs;
			indices		= other.indices;
		}

		return *this;
	}

	Mesh::Mesh(Mesh&& other)
		: positions(move(other.positions)), normals(move(other.normals)), uvs(move(other.uvs)), indices(move(other.indices))
	{
	}

	Mesh & Mesh::operator=(Mesh&& other)
	{
		if (this != &other)
		{
			positions	= move(other.positions);
			normals		= move(other.normals);
			uvs			= move(other.uvs);
			indices		= move(other.indices);
		}

		return *this;
	}

	std::size_t Mesh::getNumVertices(void) const
	{
		return std::size_t();
	}

	float const* Mesh::getPositions(void) const
	{
		return hasPositions() ? &(positions[0].x) : nullptr;
	}

	float const* Mesh::getNormals(void) const
	{
		return hasNormals() ? &(normals[0].x) : nullptr;
	}

	float const* Mesh::getUVs(void) const
	{
		return hasUVs() ? &(uvs[0].x) : nullptr;
	}

	std::size_t Mesh::getNumTriangles(void) const
	{
		return static_cast<std::size_t>( indices.size() * 0.3333333f );
	}

	bool Mesh::hasPositions(void) const
	{
		return !positions.empty();
	}

	bool Mesh::hasNormals(void) const
	{
		return !normals.empty();
	}

	bool Mesh::hasUVs(void) const
	{
		return !uvs.empty();
	}
};