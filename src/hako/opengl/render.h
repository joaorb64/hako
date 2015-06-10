#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_RENDER_H
#define HAKO_OPENGL_RENDER_H


#include <hako/engine/bindings.h>


namespace Hako
{
	class Engine;


	namespace OpenGL
	{
		// Render current OpenGL commandlists using system-independent functions.
		void render(Hako::Engine* engine);
		void execute_commandlist(Hako::OpenGL::CommandList* cl);
	}
}


#endif


#endif

