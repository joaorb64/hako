#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_OPENGL_RENDER_H
#define HAKO_OPENGL_RENDER_H


namespace Hako
{
	class Engine;

	// Render current OpenGL frame using system-independent functions.
	void common_opengl_render(Hako::Engine* engine);
}


#endif


#endif

