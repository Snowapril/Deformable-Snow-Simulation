#ifndef TOON_VERTEX_BUFFER_OBJECT_H
#define TOON_VERTEX_BUFFER_OBJECT_H

#include "ToonBaseObject.h"
#include "ToonFormat.h"
#include "ToonPrerequisites.h"
#include "ToonPlatform.h"

#include <vector>
#include <memory>

namespace Toon
{
	struct VertexAttribData
	{
		void* data; // first 1byte represents reference count.
		DataFormat description;
		int index;
		int numVertices;
	};

	class VertexBufferObject : public BaseObject
	{
		using super_t = BaseObject;
	public:
		VertexBufferObject() = default;
		VertexBufferObject(std::shared_ptr<ArrayObject> _vao) noexcept;
		VertexBufferObject(VertexBufferObject const&) noexcept;
		VertexBufferObject& operator=(VertexBufferObject const&) noexcept;
		VertexBufferObject(VertexBufferObject&&) noexcept;
		VertexBufferObject& operator=(VertexBufferObject&&) noexcept;
		~VertexBufferObject() noexcept;

		bool init() noexcept override;
		void release() noexcept override;
		void bind() const noexcept override;
		void unbind() const noexcept override;
		void bindToGPU(bool _deleteAfterPush = false) noexcept override;
	public:
		void addVertexDescription(VertexAttribData _description, unsigned int _numVertices) noexcept;
		void setVertexArrayObject(std::shared_ptr<ArrayObject> _vao) noexcept
		{
			vaoPtr = _vao;
		}
		TOON_FORCE_INLINE std::shared_ptr<ArrayObject> getVertexArrayObject() const noexcept
		{
			return vaoPtr;
		}
		TOON_FORCE_INLINE unsigned int getNumberOfVertices() const noexcept
		{
			return numberOfVertices;
		}
	private:
		std::shared_ptr< ArrayObject > vaoPtr = nullptr;
		std::vector< VertexAttribData > descriptionArray;
		unsigned int numberOfVertices = 0U;
	};
};

#endif	