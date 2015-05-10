#ifdef HAKO_BUILD_GFXOPENGL


#include "init.h"


#ifdef HAKO_BUILD_LINUX

void HakoInternal::OpenGL::linux_enable(Display* display, Window* window)
{
	GLint		att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	GLXContext	glc;
	XVisualInfo	*vi;

	vi = glXChooseVisual(display, 0, att);

	glc = glXCreateContext(display, vi, NULL, GL_TRUE);
	glXMakeCurrent(display, *window, glc);
}

#endif


#endif
