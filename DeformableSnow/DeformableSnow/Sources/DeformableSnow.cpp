#include "stdafx.h"
#include "DeformableSnow.h"

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace Toon
{
	DeformableSnow::DeformableSnow(int _numVerticesPerUnit, int _width, int _height, int _innerLOD, int _outerLOD) noexcept
		: width(_width), height(_height), innerLOD(_innerLOD), outerLOD(_outerLOD)
	{
	}

	DeformableSnow::~DeformableSnow() noexcept
	{
	}

	bool DeformableSnow::resetTerrain(int _numVerticesPerUnit) noexcept
	{
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
	}

	void DeformableSnow::debugScene(float dt) const noexcept
	{
	}

};