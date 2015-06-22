#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_MATERIAL_H
#define HAKO_OPENGL_MATERIAL_H


#include <hako/common/ds/vector.h>
#include <hako/common/ds/flatmap.h>
#include <hako/engine/abstract_bindings.h>
#include <hako/engine/gfx/shaderdata.h>
#include <hako/engine/gfx/enums.h>
#include "gl_includes.h"


namespace Hako
{
	namespace OpenGL
	{
		class Material
		{
			friend class RenderManager;


		public:
			void init        (Hako::Engine* engine);
			void set_shaders (Hako::Gfx::ShaderData* vertex_shader, Hako::Gfx::ShaderData* pixel_shader);
			void set_ztest   (Hako::Gfx::MaterialZTest ztest);
			void finish      ();

			int get_uniform_slot(Hako::Gfx::DataFormat format, Hako::String name);


		protected:
			Hako::Engine* engine;

			Hako::Gfx::ShaderData* vertex_shader;
			Hako::Gfx::ShaderData* pixel_shader;

			GLuint gl_vertex_shader;
			GLuint gl_pixel_shader;
			GLuint gl_program;

			Hako::Gfx::MaterialZTest ztest;

			Hako::DS::Vector<GLint>                       attribute_slots;

			Hako::DS::Vector<GLint>                       data_slots[(unsigned int)Hako::Gfx::DataFormat::Last];
			Hako::DS::FlatMap<Hako::String, unsigned int> data_maps[(unsigned int)Hako::Gfx::DataFormat::Last];

			void add_slot(Hako::Gfx::ShaderData::Buffer* uniform);
		};
	}
}


#endif


#endif



