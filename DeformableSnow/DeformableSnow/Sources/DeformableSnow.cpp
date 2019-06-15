#include "stdafx.h"
#include "DeformableSnow.h"

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "ToonFormat.h"
#include "ToonVertexBufferObject.h"
#include "ToonIndexBufferObject.h"
#include "ToonArrayObject.h"

namespace Toon
{
	DeformableSnow::DeformableSnow(int _numVerticesPerUnit, int _width, int _height, int _innerLOD, int _outerLOD) noexcept
		: width(_width), height(_height), innerLOD(_innerLOD), outerLOD(_outerLOD)
	{
	}

	DeformableSnow::~DeformableSnow() noexcept
	{
	}

	bool DeformableSnow::resetTerrain(std::shared_ptr<ArrayObject> _vao, int _numVerticesPerUnit) noexcept
	{
		int numRow = height * _numVerticesPerUnit;
		int numCol =  width * _numVerticesPerUnit;

		auto vbo = std::make_shared<VertexBufferObject>(_vao);
		auto ibo = std::make_shared<IndexBufferObject>(_vao);
		vbo->setVertexArrayObject(_vao);
		float vertices[] = {
			0.5f, 0.0f, 0.5f,
			0.5f, 0.0f, -0.5f,
			-0.5f, 0.0f, -0.5f,
			-0.5f, 0.0f, 0.5f
		};
		float normals[] = {
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		};
		float uvs[] = {
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f
		};
		vbo->addVertexDescription({ vertices, DataFormat::R32G32B32_FLOAT, 0 }, sizeof(uvs) / sizeof(float));
		vbo->addVertexDescription({ normals, DataFormat::R32G32B32_FLOAT, 1 } , sizeof(uvs) / sizeof(float));
		vbo->addVertexDescription({	uvs, DataFormat::R32G32_FLOAT, 2 }, sizeof(uvs) / sizeof(float));

		unsigned int indices[] = {
			0U, 1U, 2U, 2U, 3U, 0U
		};
		ibo->setIndicesPointer(indices, sizeof(indices) / sizeof(unsigned int));

		terrainMesh.addVertexBufferObject(vbo);
		terrainMesh.addIndexBufferObject(ibo);

		return true;
	}

	void DeformableSnow::setTerrainSize(int _width, int _height) noexcept
	{
		this->width		= _width;
		this->height	= _height;
	}

	void DeformableSnow::setLOD(int _innerLOD, int _outerLOD) noexcept
	{
		this->innerLOD = _innerLOD;
		this->outerLOD = _outerLOD;
	}

	void DeformableSnow::preDrawScene(void) const noexcept
	{
	}

	void DeformableSnow::drawScene(void) const noexcept
	{
		terrainMesh.renderIndexed(PrimitiveFormat::TRIANGLES);
	}

	void DeformableSnow::debugScene(float dt) const noexcept
	{
	}

};