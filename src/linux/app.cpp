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
			Window window;

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
			unsigned long window_mask;
			XSizeHints size_hints;

			window_mask = CWBackPixel | CWBorderPixel;

			// Create the window.
			window = XCreateWindow(display,
							RootWindow(display, screen),
							x, y, width, height,
							2,depth,
							InputOutput,
							CopyFromParent,
							window_mask,
							&window_attributes);

			XSetStandardProperties(display, window, title, "icon_name", None,
						 0, 0, NULL);

			// Set size and position hints.
			size_hints.flags = PPosition | PSize;

			XSetNormalHints(display, window, &size_hints);

			//Map window
			XMapWindow(display, window);
			XFlush(display);

			return 0;
		}

		int App::main_loop(Hako::Options* options)
		{
			XEvent  event;

			for(;;)
			{
				XNextEvent(display, &event);

				switch (event.type)
				{

				}
			}

			return 0;
		}
	}
}


#endif

