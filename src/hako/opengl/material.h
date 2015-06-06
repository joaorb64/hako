#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_OPENGL_MATERIAL_H
#define HAKO_OPENGL_MATERIAL_H


#include <hako/engine/bindings.h>
#include <hako/engine/gfx/material.h>
#include "gl_includes.h"


namespace Hako
{
	namespace OpenGL
	{
		void execute_commandlist(Hako::Gfx::CommandList* cl);
	}

	namespace Gfx
	{
		class Material_OpenGL : public Hako::Gfx::Material_Generic
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::Gfx::CommandList* cl);

		public:
			void init        (Hako::Engine* engine) override;
			void set_shaders (ShaderData* vertex_shader, ShaderData* pixel_shader) override;
			void set_ztest   (ZTest ztest) override;
			void finish      () override;

			int  get_float_slot   (Hako::String* name) override;
			int  get_float2_slot  (Hako::String* name) override;
			int  get_float3_slot  (Hako::String* name) override;
			int  get_float4_slot  (Hako::String* name) override;
			int  get_texture_slot (Hako::String* name) override;
			int  get_matrix4_slot (Hako::String* name) override;


		protected:
			Hako::Engine* engine;

			ShaderData* vertex_shader;
			ShaderData* pixel_shader;

			GLuint gl_vertex_shader;
			GLuint gl_pixel_shader;
			GLuint gl_program;

			ZTest ztest;

			Hako::DS::Vector<GLuint> uniform_float_slots;
			Hako::DS::Vector<GLuint> uniform_float2_slots;
			Hako::DS::Vector<GLuint> uniform_float3_slots;
			Hako::DS::Vector<GLuint> uniform_float4_slots;
			Hako::DS::Vector<GLuint> uniform_matrix4_slots;
			Hako::DS::Vector<GLuint> uniform_texture_slots;

			void add_slot(ShaderData::Uniform* uniform);
		};
	}
}


#endif


#endif



