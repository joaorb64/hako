#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_MESH_H
#define HAKO_OPENGL_MESH_H


#include <hako/common/debug.h>
#include <hako/engine/gfx/enums.h>
#include "gl_includes.h"



namespace Hako
{
	class Engine;


	namespace OpenGL
	{
		class CommandList;


		int get_format_element_num(Hako::Gfx::DataFormat format);


		class VertexBuffer
		{
			friend class RenderManager;


		public:
			VertexBuffer();
			~VertexBuffer();

			void init(
				Hako::Engine* engine,
				Hako::Gfx::DataFormat format,
				unsigned int vertex_number);

			void set_data (unsigned int start_vertex, unsigned int length, float* data);
			void finish   ();


		protected:
			HAKO_ONLYINDEBUG(bool init_called;)
			HAKO_ONLYINDEBUG(bool finish_called;)

			Hako::Gfx::DataFormat  buffer_format;
			unsigned int           vertex_number;

			GLuint gl_buffer;
		};



		class IndexBuffer
		{
			friend class RenderManager;


		public:
			IndexBuffer();
			~IndexBuffer();

			void init     (Hako::Engine* engine, unsigned int index_number);
			void set_data (unsigned int start_index, unsigned int length, unsigned int* data);
			void finish   ();


		protected:
			HAKO_ONLYINDEBUG(bool init_called;)
			HAKO_ONLYINDEBUG(bool finish_called;)
			unsigned int index_number;

			GLuint gl_buffer;
		};
	}
}


#endif


#endif



