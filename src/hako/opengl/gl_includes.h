#ifndef HAKO_OPENGL_INCLUDES_H
#define HAKO_OPENGL_INCLUDES_H


#ifdef HAKO_PLATFORM_WIN32
	#include <windows.h>
	#include <gl/gl.h>
	#include "gl_includes_win32.h"
#endif

#ifdef HAKO_PLATFORM_LINUX
	#include <GL/glx.h>
	#include <GL/gl.h>
	#include <X11/X.h>
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
	#include "gl_includes_linux.h"
#endif


namespace Hako
{
	namespace OpenGL
	{
		void check_error(const char* file, int line);
	}
}


#define HAKO_OPENGL_CHECKERROR() Hako::OpenGL::check_error(__FILE__, __LINE__)


#endif
