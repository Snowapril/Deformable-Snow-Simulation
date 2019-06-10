#ifndef TOON_STATIC_MESH_H
#define TOON_STATIC_MESH_H

namespace Toon
{
	/****************************************************************************
						Static Mesh class  declaration
	****************************************************************************/
	class StaticMesh
	{
	protected:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int IBO;
		unsigned int MeshFormat; // actually dummy variable for aligned memory
	public:
		StaticMesh() = default;
		StaticMesh(void* _vertices, unsigned int _interpret_format) noexcept;
		StaticMesh(StaticMesh const &);
		StaticMesh& operator=(StaticMesh const &);
		StaticMesh(StaticMesh&&);
		StaticMesh& operator=(StaticMesh&&);
	public:
		void bindMesh(void) const noexcept;
		void unbindMesh(void) const noexcept;
	};
};

#endif