#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_MATERIAL_H
#define HAKO_OPENGL_MATERIAL_H


#include <hako/engine/abstract_bindings.h>
#include <hako/engine/gfx/shaderdata.h>
#include <hako/engine/gfx/enums.h>
#include "gl_includes.h"


namespace Hako
{
	namespace OpenGL
	{
		void execute_commandlist(Hako::OpenGL::CommandList* cl);


		class Material
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::OpenGL::CommandList* cl);


		public:
			void init        (Hako::Engine* engine);
			void set_shaders (Hako::Gfx::ShaderData* vertex_shader, Hako::Gfx::ShaderData* pixel_shader);
			void set_ztest   (Hako::Gfx::MaterialZTest ztest);
			void finish      ();

			int  get_float_slot   (Hako::String* name);
			int  get_float2_slot  (Hako::String* name);
			int  get_float3_slot  (Hako::String* name);
			int  get_float4_slot  (Hako::String* name);
			int  get_texture_slot (Hako::String* name);
			int  get_matrix4_slot (Hako::String* name);


		protected:
			Hako::Engine* engine;

			Hako::Gfx::ShaderData* vertex_shader;
			Hako::Gfx::ShaderData* pixel_shader;

			GLuint gl_vertex_shader;
			GLuint gl_pixel_shader;
			GLuint gl_program;

			Hako::Gfx::MaterialZTest ztest;

			Hako::DS::Vector<GLuint> uniform_float_slots;
			Hako::DS::Vector<GLuint> uniform_float2_slots;
			Hako::DS::Vector<GLuint> uniform_float3_slots;
			Hako::DS::Vector<GLuint> uniform_float4_slots;
			Hako::DS::Vector<GLuint> uniform_matrix4_slots;
			Hako::DS::Vector<GLuint> uniform_texture_slots;

			void add_slot(Hako::Gfx::ShaderData::Uniform* uniform);
		};
	}
}


#endif


#endif



