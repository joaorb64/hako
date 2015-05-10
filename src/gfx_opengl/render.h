#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_GFXOPENGL_RENDER_H
#define HAKO_GFXOPENGL_RENDER_H


#include "../common/options.h"


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


namespace HakoInternal
{
	namespace OpenGL
	{
		// Render current OpenGL frame using system-independent functions.
		void render();


	#ifdef HAKO_BUILD_WIN32
		// Swap frame buffers for the given Win32 window.
		void win32_swap_buffers(HWND hwnd, HDC* hdc, HGLRC* hrc);
	#endif


	#ifdef HAKO_BUILD_LINUX
		// Swap frame buffers for the given Linux X window.
		void linux_swap_buffers(Display* display, Window* window);
	#endif

	}
}


#endif


#endif

