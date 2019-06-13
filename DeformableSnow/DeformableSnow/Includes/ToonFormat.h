#ifndef TOON_FORMAT_H
#define TOON_FORMAT_H

#include <glew/glew.h>

namespace Toon
{
	enum class TOON_VERTEX_FORMAT : unsigned int
	{
		R8G8B8A8_UINT		= 0x00000000, //  32 bit
		R8G8B8A8_SINT		= 0x00000001, //  32 bit
		R8G8B8A8_FLOAT		= 0x00000002, //  32 bit
		R16G16B16A16_UINT	= 0x00000004, //  64 bit
		R16G16B16A16_SINT	= 0x00000008, //  64 bit
		R16G16B16A16_FLOAT	= 0x00000010, //  64 bit
		R32G32B32A32_UINT	= 0x00000020, // 128 bit
		R32G32B32A32_SINT	= 0x00000040, // 128 bit
		R32G32B32A32_FLOAT	= 0x00000080, // 128 bit
	};

	enum class TOON_MESH_FORMAT : unsigned int
	{
		P3N3U2_NO_INDEX = 0x00000000, // position 3 normal 3 uv 2 index X
		P3N3U2_INDEX	= 0x00000001, // position 3 normal 3 uv 2 index O
		P3N3_NO_INDEX	= 0x00000002, // position 3 normal 3 uv X index X
		P3N3_INDEX		= 0x00000004, // position 3 normal 3 uv X index O
		P3U2_NO_INDEX	= 0x00000008, // position 3 normal X uv 2 index X
		P3U2_INDEX		= 0x00000010, // position 3 normal X uv 2 index O
		U2_NO_INDEX		= 0x00000020, // position X normal X uv 2 index X
		U2_INDEX		= 0x00000040, // position X normal X uv 2 index O
		N3_NO_INDEX		= 0x00000080, // position X normal 3 uv X index X
		N3_INDEX		= 0x00000100, // position X normal 3 uv X index O
		P3_NO_INDEX		= 0x00000200, // position 3 normal X uv X index X
		P3_INDEX		= 0x00000400, // position 3 normal X uv X index O
	};

	enum class TOON_OBJECT_FORMAT : unsigned int
	{
		VERTEX_ARRAY_OBJECT  = 0x00000000,
		INDEX_BUFFER_OBJECT  = 0x00000001,
		VERTEX_BUFFER_OBJECT = 0x00000002,
	};

	enum class TOON_PRIMITIVE_FORMAT : unsigned int
	{
		POINTS					 = 0x00000000,
		LINES					 = 0x00000001,
		LINE_LOOP				 = 0x00000002,
		LINE_STRIP				 = 0x00000004,
		TRIANGLES				 = 0x00000008,
		TRIANGLE_STRIP			 = 0x00000010,
		TRIANGLE_FAN			 = 0x00000020,
		LINES_ADJACENCY			 = 0x00000040,
		LINE_STRIP_ADJACENCY	 = 0x00000080,
		TRIANGLES_ADJACENCY		 = 0x00000100,
		TRIANGLE_STRIP_ADJACENCY = 0x00000200
	};
};

#endif