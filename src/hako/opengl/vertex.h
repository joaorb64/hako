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


		int get_format_element_num(Hako::Gfx::BufferFormat format);
		void render(Hako::Engine* engine);
		void execute_commandlist(Hako::OpenGL::CommandList* cl);


		class VertexBuffer
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::OpenGL::CommandList* cl);


		public:
			~VertexBuffer();

			void init(
				Hako::Engine* engine,
				Hako::Gfx::BufferFormat format,
				unsigned int vertex_number);

			void set_data (unsigned int start_vertex, unsigned int length, float* data);
			void finish   ();


		protected:
			Hako::Gfx::BufferFormat  buffer_format;
			unsigned int             vertex_number;

			GLuint gl_buffer;
		};



		class IndexBuffer
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::OpenGL::CommandList* cl);


		public:
			~IndexBuffer();

			void init     (Hako::Engine* engine, unsigned int index_number);
			void set_data (unsigned int start_index, unsigned int length, unsigned int* data);
			void finish   ();


		protected:
			unsigned int index_number;

			GLuint gl_buffer;
		};
	}
}


#endif


#endif



