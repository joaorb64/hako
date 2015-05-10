#ifdef HAKO_BUILD_LINUX


#include "app.h"
#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


namespace HakoInternal
{
	namespace Linux
	{
		int App::init(Hako::Options* options)
		{
			int screen;
			int depth;

			display = XOpenDisplay(NULL);
			screen = DefaultScreen(display);
			depth = DefaultDepth(display,screen);

			int x       = 0;
			int y       = 0;
			int width   = 640;
			int height  = 480;
			int flag    = 0;
			char* title = "Hako Game Engine";

			XSetWindowAttributes window_attributes;
			window_attributes.event_mask = ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask;

			unsigned long window_mask;
			XSizeHints size_hints;

			window_mask = CWBackPixel | CWBorderPixel | CWEventMask;

			// Create the window.
			window = XCreateWindow(display,
							RootWindow(display, screen),
							x, y, width, height,
							2,depth,
							InputOutput,
							CopyFromParent,
							window_mask,
							&window_attributes);

			XSetStandardProperties(display, window, title, "icon_name", None, 0, 0, NULL);

			// Set size and position hints.
			size_hints.flags = PPosition | PSize;

			XSetNormalHints(display, window, &size_hints);

			//Map window
			XMapWindow(display, window);
			XFlush(display);

			init_gl();

			return 0;
		}

		void App::init_gl()
		{
			GLint		att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
			GLXContext	glc;
			XVisualInfo	*vi;

			vi = glXChooseVisual(display, 0, att);

			glc = glXCreateContext(display, vi, NULL, GL_TRUE);
			glXMakeCurrent(display, window, glc);

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			glClearDepth(1.0);
			glClearColor(0.0, 0.0, 0.0, 0.0);

			render_gl();
		}

		void App::render_gl()
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

			glXSwapBuffers(display, window);
		}

		int App::main_loop(Hako::Options* options)
		{
			XEvent  event;

			for(;;)
			{
				XNextEvent(display, &event);

				switch (event.type)
				{
					case Expose:
						render_gl();
					break;
				}
			}

			return 0;
		}
	}
}


#endif

