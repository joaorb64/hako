#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_OPENGL_MANAGER_H
#define HAKO_OPENGL_MANAGER_H


#include <hako/engine/gfx/manager.h>
#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;

	namespace OpenGL
	{
		void render(Hako::Engine* engine);
		void execute_commandlist(Hako::Gfx::CommandList_Generic* cl);
	}

	namespace Gfx
	{
		class Manager_OpenGL : public Hako::Gfx::Manager_Generic
		{
			friend void Hako::OpenGL::render(Hako::Engine* engine);

		public:
			void init(Hako::Engine* engine);
			void commandlist_add(Hako::Gfx::CommandList_Generic* commandlist) override;

		protected:
			Hako::DS::Vector<Hako::Gfx::CommandList_Generic*> commandlists;
		};
	}
}


#endif


#endif

