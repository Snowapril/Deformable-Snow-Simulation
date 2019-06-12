#ifndef TOON_MESH_H
#define TOON_MESH_H

#include "ToonBaseObject.h"
#include "ToonFormat.h"
#include "ToonArrayObject.h"

namespace Toon
{
	/****************************************************************************
						Static Mesh class  declaration
	****************************************************************************/
	class Mesh : public BaseObject
	{
		using super_t = BaseObject;
	public:
		Mesh() = default;
		Mesh(void* _vertices, TOON_MESH_FORMAT _interpret_format) noexcept;
		Mesh(Mesh const &) noexcept;
		Mesh& operator=(Mesh const &) noexcept;
		Mesh(Mesh&&) noexcept;
		Mesh& operator=(Mesh&&) noexcept;
		~Mesh() noexcept;

		bool init() noexcept override;
		void release() noexcept override;
		void bind() const noexcept override;
		void unbind() const noexcept override;
		void bindToGPU(bool _deleteAfterPush = false) noexcept override;
	public:
		void allocateVertexData(void* _vertices, TOON_MESH_FORMAT _interpret_format) noexcept;
	protected: 
		// in this case, inherited member variable "objectID" will be a Vertex Array Object
		void* data;
		ArrayObject vao;
		TOON_MESH_FORMAT MeshFormat; // actually dummy variable for aligned memory
	};
};

#endif