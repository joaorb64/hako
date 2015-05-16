#ifdef HAKO_BUILD_LINUX


#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#ifdef HAKO_BUILD_GFXOPENGL
	#include <hako/common_gl/render.h>
#endif


Display* linux_display;
Window   linux_window;


int main(int argc, char** argv)
{
	HAKO_UNUSED(argc);
	HAKO_UNUSED(argv);

	Hako::Engine engine;
	engine.init();

	Hako::Application::init_start(&engine);


	int screen;
	int depth;

	linux_display = XOpenDisplay(NULL);
	screen = DefaultScreen(linux_display);
	depth = DefaultDepth(linux_display, screen);

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
	linux_window = XCreateWindow(linux_display,
					RootWindow(linux_display, screen),
					x, y, width, height,
					2,depth,
					InputOutput,
					CopyFromParent,
					window_mask,
					&window_attributes);

	XSetStandardProperties(linux_display, linux_window, title, "icon_name", None, 0, 0, NULL);

	// Set size and position hints.
	size_hints.flags = PPosition | PSize;

	XSetNormalHints(linux_display, linux_window, &size_hints);

	// Map window.
	XMapWindow(linux_display, linux_window);
	XFlush(linux_display);

#ifdef HAKO_BUILD_GFXOPENGL
	linux_opengl_enable(linux_display, &linux_window);
#endif


	Hako::Application::init_end(&engine);


	XEvent  event;

	for(;;)
	{
		XNextEvent(linux_display, &event);

		switch (event.type)
		{
			case Expose:
			{
			#ifdef HAKO_BUILD_GFXOPENGL
				Hako::common_opengl_render();
				glXSwapBuffers(linux_display, *linux_window);
			#endif
				break;
			}
		}
	}

	return 0;
}


void linux_opengl_enable(Display* display, Window* window)
{
	GLint		att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	GLXContext	glc;
	XVisualInfo	*vi;

	vi = glXChooseVisual(display, 0, att);

	glc = glXCreateContext(display, vi, NULL, GL_TRUE);
	glXMakeCurrent(display, *window, glc);
}


#endif

