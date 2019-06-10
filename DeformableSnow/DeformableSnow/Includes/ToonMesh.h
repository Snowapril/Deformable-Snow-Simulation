#ifndef TOON_MESH_H
#define TOON_MESH_H

namespace Toon
{
	/****************************************************************************
						Static Mesh class  declaration
	****************************************************************************/
	class Mesh
	{
	protected:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int IBO;
		unsigned int MeshFormat; // actually dummy variable for aligned memory
	public:
		Mesh() = default;
		Mesh(void* _vertices, unsigned int _interpret_format) noexcept;
		Mesh(Mesh const &);
		Mesh& operator=(Mesh const &);
		Mesh(Mesh&&);
		Mesh& operator=(Mesh&&);
	public:
		void bindMesh(void) const noexcept;
		void unbindMesh(void) const noexcept;
	};
};

#endif