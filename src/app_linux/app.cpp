#ifdef HAKO_BUILD_LINUX


#include "app.h"
#include "../gfx_opengl/init.h"
#include "../gfx_opengl/render.h"
#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


namespace HakoInternal
{
	int LinuxApp::init(Hako::Options* options)
	{
		int screen;
		int depth;

		m_display = XOpenDisplay(NULL);
		screen = DefaultScreen(m_display);
		depth = DefaultDepth(m_display, screen);

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
		m_window = XCreateWindow(m_display,
						RootWindow(m_display, screen),
						x, y, width, height,
						2,depth,
						InputOutput,
						CopyFromParent,
						window_mask,
						&window_attributes);

		XSetStandardProperties(m_display, m_window, title, "icon_name", None, 0, 0, NULL);

		// Set size and position hints.
		size_hints.flags = PPosition | PSize;

		XSetNormalHints(m_display, m_window, &size_hints);

		// Map window.
		XMapWindow(m_display, m_window);
		XFlush(m_display);

	#ifdef HAKO_BUILD_GFXOPENGL
		linux_opengl_enable(m_display, &m_window);
	#endif

		return 0;
	}


	int LinuxApp::main_loop(Hako::Options* options)
	{
		XEvent  event;

		for(;;)
		{
			XNextEvent(m_display, &event);

			switch (event.type)
			{
				case Expose:
				{
				#ifdef HAKO_BUILD_GFXOPENGL
					OpenGL::render();
					OpenGL::linux_swap_buffers(m_display, &m_window);
				#endif
					break;
				}
			}
		}

		return 0;
	}
}


#endif

