#ifndef TOON_FORMAT_H
#define TOON_FORMAT_H

namespace Toon
{
	struct DataFormat
	{
		unsigned int stride = 0U;
		unsigned int dataType = 0U;
		unsigned int size = 0U;
		bool bNormalized = false;

		DataFormat() = default;
		DataFormat(unsigned int size, unsigned int dataType, bool _bNormalized, unsigned int stride) noexcept;

		static DataFormat R32G32_SINT;
		static DataFormat R32G32_UINT;
		static DataFormat R32G32_SNORM;
		static DataFormat R32G32_UNORM;
		static DataFormat R32G32_FLOAT;
		static DataFormat R32G32B32_SINT;
		static DataFormat R32G32B32_UINT;
		static DataFormat R32G32B32_SNORM;
		static DataFormat R32G32B32_UNORM;
		static DataFormat R32G32B32_FLOAT;
		static DataFormat R32G32B32A32_SINT;
		static DataFormat R32G32B32A32_UINT;
		static DataFormat R32G32B32A32_SNORM;
		static DataFormat R32G32B32A32_UNORM;
		static DataFormat R32G32B32A32_FLOAT;
	};

	enum class TOON_VERTEX_FORMAT : unsigned int
	{
		POSITION	= 0x00000001,
		NORMAL		= 0x00000002,
		UV			= 0x00000004
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