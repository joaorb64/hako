#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_COMMANDLIST_H
#define HAKO_OPENGL_COMMANDLIST_H


#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;

	namespace OpenGL
	{
		class CommandList;
		class Material;
		class Mesh;


		void execute_commandlist(Hako::OpenGL::CommandList* cl);


		class CommandList
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::OpenGL::CommandList* cl);


		public:
			~CommandList         ();
			void init            (Hako::Engine* engine);
			void clear           ();

            void begin           ();
            void set_material    (Hako::OpenGL::Material* material);
            void draw            (Hako::OpenGL::Mesh* mesh);
            void finish          ();


		protected:
			class Command
			{
			public:
				enum class Kind
				{
					SetMaterial,
					Draw
				};

				Kind kind;
				union
				{
					Hako::OpenGL::Material* material;
					Hako::OpenGL::Mesh*     mesh;
				} command_data;
			};


			Hako::DS::Vector<Command> commands;
		};
	}
}


#endif


#endif

