#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_COMMANDLIST_H
#define HAKO_OPENGL_COMMANDLIST_H


#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;

	namespace OpenGL
	{
		class Material;
		class VertexBuffer;
		class IndexBuffer;



		class CommandList
		{
			friend class RenderManager;


		public:
			~CommandList            ();
			void init               (Hako::Engine* engine);
			void clear              ();

            void begin              ();
            void set_material       (Hako::OpenGL::Material* material);
            void set_vertex_buffer  (unsigned int index, Hako::OpenGL::VertexBuffer* buffer);
            void draw_indexed       (Hako::OpenGL::IndexBuffer* buffer);
            void finish             ();


		protected:
			class Command
			{
			public:
				enum class Kind
				{
					SetMaterial,
					SetVertexBuffer,
					DrawIndexed
				};

				Kind kind;
				unsigned int index;
				union
				{
					Hako::OpenGL::Material*     material;
					Hako::OpenGL::VertexBuffer* vertex_buffer;
					Hako::OpenGL::IndexBuffer*  index_buffer;
				} command_data;
			};


			Hako::DS::Vector<Command> commands;
		};
	}
}


#endif


#endif

