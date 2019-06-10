#include "stdafx.h"
#include "ToonDynamicMesh.h"

namespace Toon
{
	/****************************************************************************
						Mesh class  definition
	****************************************************************************/
	DynamicMesh::DynamicMesh(DynamicMesh const& other)
		: positions(other.positions), normals(other.normals), uvs(other.uvs), indices(other.indices)
	{
	}

	DynamicMesh& DynamicMesh::operator=(DynamicMesh const& other)
	{
		if (this != &other)
		{
			positions = other.positions;
			normals = other.normals;
			uvs = other.uvs;
			indices = other.indices;
		}

		return *this;
	}

	DynamicMesh::DynamicMesh(DynamicMesh&& other)
		: positions(move(other.positions)), normals(move(other.normals)), uvs(move(other.uvs)), indices(move(other.indices))
	{
	}

	DynamicMesh& DynamicMesh::operator=(DynamicMesh&& other)
	{
		if (this != &other)
		{
			positions = move(other.positions);
			normals = move(other.normals);
			uvs = move(other.uvs);
			indices = move(other.indices);
		}

		return *this;
	}

	std::size_t DynamicMesh::getNumVertices(void) const
	{
		return std::size_t();
	}

	float const* DynamicMesh::getPositions(void) const
	{
		return hasPositions() ? &(positions[0].x) : nullptr;
	}

	float const* DynamicMesh::getNormals(void) const
	{
		return hasNormals() ? &(normals[0].x) : nullptr;
	}

	float const* DynamicMesh::getUVs(void) const
	{
		return hasUVs() ? &(uvs[0].x) : nullptr;
	}


	bool DynamicMesh::hasPositions(void) const
	{
		return !positions.empty();
	}

	bool DynamicMesh::hasNormals(void) const
	{
		return !normals.empty();
	}

	bool DynamicMesh::hasUVs(void) const
	{
		return !uvs.empty();
	}

	std::size_t DynamicMesh::getNumTriangles(void) const
	{
		return static_cast<std::size_t>(indices.size() * 0.3333333f);
	}
};