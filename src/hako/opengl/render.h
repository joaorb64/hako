#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_RENDER_H
#define HAKO_OPENGL_RENDER_H


#include <hako/engine/bindings.h>


namespace Hako
{
	class Engine;


	namespace OpenGL
	{
		class RenderManager
		{
		public:
			// Render current OpenGL commandlists using system-independent functions.
			static void render(Hako::Engine* engine);

		protected:
			// Execute instructions in a commandlist.
			static void execute_commandlist(Hako::OpenGL::CommandList* cl);
		};
	}
}


#endif


#endif

