#ifndef HAKO_ENGINE_GFX_MATERIALENUMS_H
#define HAKO_ENGINE_GFX_MATERIALENUMS_H


namespace Hako
{
	namespace Gfx
	{
		enum class DepthTestFunction
		{
			AlwaysPass,
			PassIfLess,
			PassIfLessOrEqual,
			PassIfGreater,
			PassIfGreaterOrEqual
		};


		enum class DataFormat : unsigned int
		{
			Float,
			Float2,
			Float3,
			Float4,
			Matrix4,
			Texture,
			Last
		};
	}
}


#endif
