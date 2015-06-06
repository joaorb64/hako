#ifndef HAKO_ENGINE_GFX_MATERIAL_H
#define HAKO_ENGINE_GFX_MATERIAL_H


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
			void init(Hako::Engine* engine);
			void add_attribute(Attribute::Format format, int position);
			void add_uniform(Uniform::Type type, int position, Hako::String* name);
			void set_program_data(void* data, unsigned int length);
			void finish();


		public:
			Hako::DS::Vector<Attribute> attributes;
			Hako::DS::Vector<Uniform>   uniforms;

			void*          data;
			unsigned int   length;
		};


		enum class MaterialZTest
		{
			AlwaysPass,
			PassIfLess,
			PassIfLessOrEqual,
			PassIfGreater,
			PassIfGreaterOrEqual
		};


		class Material_Generic
		{
		public:
			virtual void init        (Hako::Engine* engine) = 0;
			virtual void set_shaders (ShaderData* vertex_shader, ShaderData* pixel_shader) = 0;
			virtual void set_ztest   (Hako::Gfx::MaterialZTest ztest) = 0;
			virtual void finish      () = 0;

			virtual int  get_float_slot   (Hako::String* name) = 0;
			virtual int  get_float2_slot  (Hako::String* name) = 0;
			virtual int  get_float3_slot  (Hako::String* name) = 0;
			virtual int  get_float4_slot  (Hako::String* name) = 0;
			virtual int  get_texture_slot (Hako::String* name) = 0;
			virtual int  get_matrix4_slot (Hako::String* name) = 0;
		};
	}
}


#endif





