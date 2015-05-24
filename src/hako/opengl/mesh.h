#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_OPENGL_MESH_H
#define HAKO_OPENGL_MESH_H


#include <hako/engine/gfx/mesh.h>
#include "gl_includes.h"


namespace Hako
{
	namespace Gfx
	{
		class Mesh_OpenGL : public Hako::Gfx::Mesh_Generic
		{
		public:
			~Mesh_OpenGL();

			void init(
				Hako::Engine*    engine,
				unsigned int     attrib_number,
				AttributeFormat* attrib_formats,
				unsigned int     vertex_number,
				unsigned int     index_number) override;

			void set_data_float  (unsigned int attrib_index, float* data) override;
			void set_data_float2 (unsigned int attrib_index, float* data) override;
			void set_data_float3 (unsigned int attrib_index, float* data) override;
			void set_data_float4 (unsigned int attrib_index, float* data) override;
			void set_indices     (unsigned int* indices) override;
			void finish          () override;


		protected:
			Hako::Engine*    engine;
			unsigned int     attrib_number;
			AttributeFormat* attrib_formats;
			unsigned int     vertex_number;
			unsigned int     index_number;

			GLuint          gl_vertex_array_object;
			GLuint*         gl_data_buffers;
			GLuint          gl_index_buffer;
		};
	}
}


#endif


#endif



