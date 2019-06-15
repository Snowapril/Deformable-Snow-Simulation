#include "stdafx.h"
#include "ToonFormat.h"

#include <glew/glew.h>

namespace Toon
{
	DataFormat DataFormat::R32G32_SINT			= DataFormat(2,			 GL_INT, false, 2 * sizeof(float));
	DataFormat DataFormat::R32G32_UINT			= DataFormat(2, GL_UNSIGNED_INT, false, 2 * sizeof(float));
	DataFormat DataFormat::R32G32_SNORM			= DataFormat(2,			 GL_INT,  true, 2 * sizeof(float));
	DataFormat DataFormat::R32G32_UNORM			= DataFormat(2, GL_UNSIGNED_INT,  true, 2 * sizeof(float));
	DataFormat DataFormat::R32G32_FLOAT			= DataFormat(2,		   GL_FLOAT, false, 2 * sizeof(float));
	DataFormat DataFormat::R32G32B32_SINT		= DataFormat(3,			 GL_INT, false, 3 * sizeof(float));
	DataFormat DataFormat::R32G32B32_UINT		= DataFormat(3, GL_UNSIGNED_INT, false, 3 * sizeof(float));
	DataFormat DataFormat::R32G32B32_SNORM		= DataFormat(3,			 GL_INT,  true, 3 * sizeof(float));
	DataFormat DataFormat::R32G32B32_UNORM		= DataFormat(3, GL_UNSIGNED_INT,  true, 3 * sizeof(float));
	DataFormat DataFormat::R32G32B32_FLOAT		= DataFormat(3,		   GL_FLOAT, false, 3 * sizeof(float));
	DataFormat DataFormat::R32G32B32A32_SINT	= DataFormat(4,			 GL_INT, false, 4 * sizeof(float));
	DataFormat DataFormat::R32G32B32A32_UINT	= DataFormat(4, GL_UNSIGNED_INT, false, 4 * sizeof(float));
	DataFormat DataFormat::R32G32B32A32_SNORM	= DataFormat(4,			 GL_INT,  true, 4 * sizeof(float));
	DataFormat DataFormat::R32G32B32A32_UNORM	= DataFormat(4, GL_UNSIGNED_INT,  true, 4 * sizeof(float));
	DataFormat DataFormat::R32G32B32A32_FLOAT	= DataFormat(4,		   GL_FLOAT, false, 4 * sizeof(float));

	DataFormat::DataFormat(unsigned int _size, unsigned int _dataType, bool _bNormalized, unsigned int _stride) noexcept
		: size(_size), dataType(_dataType), bNormalized(_bNormalized), stride(_stride)
	{
	}

	PrimitiveFormat PrimitiveFormat::POINTS						= PrimitiveFormat(GL_POINTS);
	PrimitiveFormat PrimitiveFormat::LINES						= PrimitiveFormat(GL_LINES);
	PrimitiveFormat PrimitiveFormat::LINE_LOOP					= PrimitiveFormat(GL_LINE_LOOP);
	PrimitiveFormat PrimitiveFormat::LINE_STRIP					= PrimitiveFormat(GL_LINE_STRIP);
	PrimitiveFormat PrimitiveFormat::TRIANGLES					= PrimitiveFormat(GL_TRIANGLES);
	PrimitiveFormat PrimitiveFormat::TRIANGLE_STRIP				= PrimitiveFormat(GL_TRIANGLE_STRIP);
	PrimitiveFormat PrimitiveFormat::TRIANGLE_FAN				= PrimitiveFormat(GL_TRIANGLE_FAN);
	PrimitiveFormat PrimitiveFormat::LINES_ADJACENCY			= PrimitiveFormat(GL_LINES_ADJACENCY);
	PrimitiveFormat PrimitiveFormat::LINE_STRIP_ADJACENCY		= PrimitiveFormat(GL_LINE_STRIP_ADJACENCY);
	PrimitiveFormat PrimitiveFormat::TRIANGLES_ADJACENCY		= PrimitiveFormat(GL_TRIANGLES_ADJACENCY);
	PrimitiveFormat PrimitiveFormat::TRIANGLE_STRIP_ADJACENCY	= PrimitiveFormat(GL_TRIANGLE_STRIP_ADJACENCY);

	PrimitiveFormat::PrimitiveFormat(unsigned int _mode) noexcept
		: mode(_mode) {};

};