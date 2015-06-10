#ifndef HAKO_ENGINE_GFX_MATERIALENUMS_H
#define HAKO_ENGINE_GFX_MATERIALENUMS_H


namespace Hako
{
	namespace Gfx
	{
		enum class MaterialZTest
		{
			AlwaysPass,
			PassIfLess,
			PassIfLessOrEqual,
			PassIfGreater,
			PassIfGreaterOrEqual
		};


		enum class MeshAttributeFormat
		{
			Float,
			Float2,
			Float3,
			Float4
		};
	}
}


#endif
