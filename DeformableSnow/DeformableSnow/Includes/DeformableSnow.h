#ifndef DEFORMABLE_SNOW_H
#define DEFORMABLE_SNOW_H

#include "ToonHeaderPrefix.h"
#include "ToonNoncopyable.h"
#include "ToonMesh.h"

namespace Toon
{
	class DeformableSnow : public Noncopyable
	{
	public:
		DeformableSnow(int _numVerticesPerUnit, int _width, int _height, int _innerLOD, int _outerLOD) noexcept;
		~DeformableSnow() noexcept;

		bool resetTerrain(int _numVerticesPerUnit) noexcept;
		void setTerrainSize(int _width, int _height) noexcept;
		void setLOD(int _innerLOD, int _outerLOD) noexcept;
	public:
		void preDrawScene(void) const noexcept;
		void drawScene(void) const noexcept;
#ifdef _DEBUG
		void debugScene(float dt) const noexcept;
#endif
	private:
		Mesh terrainMesh;
		int width;
		int height;
		int innerLOD;
		int outerLOD;
	};
};

#include "ToonHeaderPostfix.h"
#endif