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

	struct PrimitiveFormat
	{
		unsigned int mode{ 0U };

		PrimitiveFormat() = default;
		PrimitiveFormat(unsigned int _mode) noexcept;

		static PrimitiveFormat POINTS;
		static PrimitiveFormat LINES;
		static PrimitiveFormat LINE_LOOP;
		static PrimitiveFormat LINE_STRIP;
		static PrimitiveFormat TRIANGLES;
		static PrimitiveFormat TRIANGLE_STRIP;
		static PrimitiveFormat TRIANGLE_FAN;
		static PrimitiveFormat LINES_ADJACENCY;
		static PrimitiveFormat LINE_STRIP_ADJACENCY;
		static PrimitiveFormat TRIANGLES_ADJACENCY;
		static PrimitiveFormat TRIANGLE_STRIP_ADJACENCY;
	};
};

#endif