#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_OPENGL_COMMANDLIST_H
#define HAKO_OPENGL_COMMANDLIST_H


#include <hako/engine/gfx/commandlist.h>
#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;

	namespace OpenGL
	{
		void execute_commandlist(Hako::Gfx::CommandList_Generic* cl);
	}

	namespace Gfx
	{
		class Material_Generic;
		class Mesh_Generic;


		class CommandList_OpenGL : public CommandList_Generic
		{
			friend void Hako::OpenGL::execute_commandlist(Hako::Gfx::CommandList_Generic* cl);

		public:
			~CommandList_OpenGL  ();
			void init            (Hako::Engine* engine) override;
			void clear           () override;

            void begin           () override;
            void set_material    (Hako::Gfx::Material_Generic* material) override;
            void draw            (Hako::Gfx::Mesh_Generic* mesh) override;
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
					Hako::Gfx::Material_Generic* material;
					Hako::Gfx::Mesh_Generic*     mesh;
				} command_data;
			};


			Hako::DS::Vector<Command> commands;
		};
	}
}


#endif


#endif

