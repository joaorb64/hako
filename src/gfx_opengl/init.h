#ifdef HAKO_BUILD_GFXOPENGL


#ifndef HAKO_GFXOPENGL_INIT_H
#define HAKO_GFXOPENGL_INIT_H


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

	#ifdef HAKO_BUILD_WIN32
		// Enable OpenGL for the given Win32 window.
		void win32_enable(HWND hwnd, HDC* hdc, HGLRC* hrc);

		// Disable OpenGL for the given Win32 window.
		void win32_disable(HWND hwnd, HDC hdc, HGLRC hrc);
	#endif


	#ifdef HAKO_BUILD_LINUX
		// Enable OpenGL for the given Linux X window.
		void linux_enable(Display* display, Window* window);
	#endif

	}
}


#endif


#endif
