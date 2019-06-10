#ifndef TOON_DYNAMIC_MESH_H
#define TOON_DYNAMIC_MESH_H

#include "ToonMaterial.h"
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>
#include <type_traits>

namespace Toon
{
	/****************************************************************************
						Dynamic Mesh class  declaration
	****************************************************************************/
	class DynamicMesh
	{
	private:
		std::vector<glm::vec3>		positions;
		std::vector<glm::vec3>		normals;
		std::vector<glm::vec2>		uvs;
		std::vector<unsigned int>	indices;
	public:
		DynamicMesh() = default;
		DynamicMesh(DynamicMesh const&);
		DynamicMesh& operator=(DynamicMesh const&);
		DynamicMesh(DynamicMesh&&);
		DynamicMesh& operator=(DynamicMesh&&);

		std::size_t  getNumVertices(void) const;
		float const* getPositions(void) const;
		float const* getNormals(void) const;
		float const* getUVs(void) const;
		std::size_t  getNumTriangles(void) const;

		bool hasPositions(void)	const;
		bool hasNormals(void)	const;
		bool hasUVs(void)	const;

		template <typename Position, typename = typename std::enable_if_t<std::is_assignable_v<glm::vec3, Position>>>
		void setPosition(std::vector<Position>&& posVec)
		{
			positions = std::move(posVec);
		}
		template <typename Normal, typename = typename std::enable_if_t<std::is_assignable_v<glm::vec3, Normal>>>
		void setNormal(std::vector<Normal>&& normVec)
		{
			normals = std::move(normVec);
		}
		template <typename UV, typename = typename std::enable_if_t<std::is_assignable_v<glm::vec2, UV>>>
		void setUV(std::vector<UV>&& uvVec)
		{
			uvs = std::move(uvVec);
		}
		void setIndices(std::vector<unsigned int>&& indexVec)
		{
			indices = std::move(indexVec);
		}
	};
};

#endif