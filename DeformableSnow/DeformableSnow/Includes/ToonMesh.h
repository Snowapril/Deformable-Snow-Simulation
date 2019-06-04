#ifndef TOON_MESH_H
#define TOON_MESH_H

#include "ToonMaterial.h"
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>

namespace Toon
{
	/****************************************************************************
						Mesh class  declaration
	****************************************************************************/
	class Mesh
	{
	private:
		std::vector<glm::vec3>		positions;
		std::vector<glm::vec3>		normals;
		std::vector<glm::vec2>		uvs;
		std::vector<unsigned int>	indices;
	public:
		Mesh() = default;
		Mesh(Mesh const &);
		Mesh& operator=(Mesh const &);
		Mesh(Mesh&&);
		Mesh& operator=(Mesh&&);

		std::size_t  getNumVertices	(void) const;
		float const* getPositions	(void) const;
		float const* getNormals		(void) const;
		float const* getUVs			(void) const;
		std::size_t  getNumTriangles(void) const;

		bool hasPositions	(void)	const;
		bool hasNormals		(void)	const;
		bool hasUVs			(void)	const;
	};
};

#endif