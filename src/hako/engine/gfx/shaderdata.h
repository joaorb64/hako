#ifndef HAKO_ENGINE_GFX_SHADERDATA_H
#define HAKO_ENGINE_GFX_SHADERDATA_H


#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;
	class String;


	namespace Gfx
	{
		class ShaderData
		{
		public:
			struct Attribute
			{
				enum class Format
				{
					Float,
					Float2,
					Float3,
					Float4
				};

				Format format;
				int    position;
			};

			struct Uniform
			{
				enum class Type
				{
					Float,
					Float2,
					Float3,
					Float4,
					Matrix4,
					Texture
				};

				Type          type;
				int           position;
				Hako::String* name;
			};


			~ShaderData();
			void init             (Hako::Engine* engine);
			void add_attribute    (Attribute::Format format, int position);
			void add_uniform      (Uniform::Type type, int position, Hako::String* name);
			void set_program_data (void* data, unsigned int length);
			void finish           ();


		public:
			Hako::DS::Vector<Attribute> attributes;
			Hako::DS::Vector<Uniform>   uniforms;

			void*          data;
			unsigned int   length;
		};
	}
}


#endif
