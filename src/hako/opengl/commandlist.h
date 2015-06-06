#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_OPENGL_COMMANDLIST_H
#define HAKO_OPENGL_COMMANDLIST_H


#include <hako/engine/gfx/commandlist.h>
#include <hako/engine/bindings.h>
#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;

	namespace OpenGL
	{
		void execute_commandlist(Hako::Gfx::CommandList* cl);
	}

	namespace Gfx
	{
		class CommandList_OpenGL : public CommandList_Generic
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::Gfx::CommandList* cl);

		public:
			~CommandList_OpenGL  ();
			void init            (Hako::Engine* engine) override;
			void clear           () override;

            void begin           () override;
            void set_material    (Hako::Gfx::Material* material) override;
            void draw            (Hako::Gfx::Mesh* mesh) override;
            void finish          () override;


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
					Hako::Gfx::Material* material;
					Hako::Gfx::Mesh*     mesh;
				} command_data;
			};


			Hako::DS::Vector<Command> commands;
		};
	}
}


#endif


#endif

