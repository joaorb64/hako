#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_GFXOPENGL_RENDER_H
#define HAKO_GFXOPENGL_RENDER_H


#ifdef HAKO_BUILD_WIN32
	#include <windows.h>
	#include <gl/gl.h>
#endif


#ifdef HAKO_BUILD_LINUX
	#include <GL/glx.h>
	#include <GL/gl.h>
	#include <X11/X.h>
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#endif


namespace Hako
{
	// Render current OpenGL frame using system-independent functions.
	void common_opengl_render();
}


#endif


#endif

