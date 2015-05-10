#ifdef HAKO_BUILD_GFXOPENGL


#include "render.h"


namespace HakoInternal
{
	namespace OpenGL
	{
		void render()
		{
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
			glViewport(0, 0, 640, 480);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(0.0, 0.0, -3.0);
			glBegin(GL_QUADS);
				glColor3f(0.0, 0.7, 0.1);
				glVertex3f(-1.0, 1.0, 1.0);
				glVertex3f(1.0, 1.0, 1.0);
				glVertex3f(1.0, -1.0, 1.0);
				glVertex3f(-1.0, -1.0, 1.0);
			glEnd();
		}


	#ifdef HAKO_BUILD_WIN32
		void win32_swap_buffers(HWND hwnd, HDC* hdc, HGLRC* hrc)
		{
			SwapBuffers(*hdc);
		}
	#endif


	#ifdef HAKO_BUILD_LINUX
		void linux_swap_buffers(Display* display, Window* window)
		{
			glXSwapBuffers(display, *window);
		}
	#endif

	}
}


#endif
