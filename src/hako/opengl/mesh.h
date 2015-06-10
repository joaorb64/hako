#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_MESH_H
#define HAKO_OPENGL_MESH_H


#include <hako/engine/gfx/enums.h>
#include "gl_includes.h"



namespace Hako
{
	class Engine;


	namespace OpenGL
	{
		class CommandList;


		void render(Hako::Engine* engine);
		void execute_commandlist(Hako::OpenGL::CommandList* cl);


		class Mesh
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::OpenGL::CommandList* cl);

		public:
			~Mesh();

			void init(
				Hako::Engine*                   engine,
				unsigned int                    attrib_number,
				Hako::Gfx::MeshAttributeFormat* attrib_formats,
				unsigned int                    vertex_number,
				unsigned int                    index_number);

			void set_data_float  (unsigned int attrib_index, float* data);
			void set_data_float2 (unsigned int attrib_index, float* data);
			void set_data_float3 (unsigned int attrib_index, float* data);
			void set_data_float4 (unsigned int attrib_index, float* data);
			void set_indices     (unsigned int* indices);
			void finish          ();


		protected:
			Hako::Engine*                    engine;
			unsigned int                     attrib_number;
			Hako::Gfx::MeshAttributeFormat*  attrib_formats;
			unsigned int                     vertex_number;
			unsigned int                     index_number;

			GLuint   gl_vertex_array_object;
			GLuint*  gl_data_buffers;
			GLuint   gl_index_buffer;
		};
	}
}


#endif


#endif



