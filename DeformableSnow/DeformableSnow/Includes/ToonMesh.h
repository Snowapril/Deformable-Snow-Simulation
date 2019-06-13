#ifndef TOON_MESH_H
#define TOON_MESH_H

#include "ToonBaseObject.h"
#include "ToonPrerequisites.h"

#include <vector>
#include <memory>

namespace Toon
{
	/****************************************************************************
						Static Mesh class  declaration
	****************************************************************************/
	class Mesh
	{
		using super_t = BaseObject;
	public:
		Mesh() = default;
		Mesh(Mesh const &) noexcept;
		Mesh& operator=(Mesh const &) noexcept;
		Mesh(Mesh&&) noexcept;
		Mesh& operator=(Mesh&&) noexcept;
		~Mesh() noexcept;
	public:
		void render(unsigned int _primitiveFormat) const noexcept;
		void renderIndexed(unsigned int _primitiveFormat) const noexcept;

		void addVertexBufferObject(std::shared_ptr< VertexBufferObject > _bufferPtr) noexcept;
		void addIndexBufferObject(std::shared_ptr< IndexBufferObject > _bufferPtr) noexcept;
	private:
		std::vector<std::shared_ptr<VertexBufferObject>> vboArray;
		std::vector<std::shared_ptr< IndexBufferObject>> iboArray;
	};
};

#endif