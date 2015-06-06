#ifdef HAKO_BUILD_LINUX


#include "window_opengl.h"
#include <hako/engine/engine.h>
#include <hako/opengl/render.h>



void Hako::Linux::WindowOpenGL::init(Hako::Engine* engine)
{
	this->user_quit = false;
	this->engine = engine;


	this->display = XOpenDisplay(NULL);
	int screen = DefaultScreen(this->display);
	int depth = DefaultDepth(this->display, screen);

	//
	//Define window attributes.
	//
	int x       = 0;
	int y       = 0;
	int width   = 960;
	int height  = 544;
	char* title = "Hako Game Engine";

	XSetWindowAttributes window_attributes;
	window_attributes.event_mask = ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask;

	unsigned long window_mask;
	XSizeHints size_hints;

	window_mask = CWBackPixel | CWBorderPixel | CWEventMask;

	// Create the window.
	this->window = XCreateWindow(this->display,
					RootWindow(this->display, screen),
					x, y, width, height,
					2,depth,
					InputOutput,
					CopyFromParent,
					window_mask,
					&window_attributes);

	XSetStandardProperties(this->display, this->window, title, "icon_name", None, 0, 0, NULL);

	// Set size and position hints.
	size_hints.flags = PPosition | PSize;

	XSetNormalHints(this->display, this->window, &size_hints);

	// Map window.
	XMapWindow(this->display, this->window);

	this->opengl_enable(this->display, &this->window);
}



void Hako::Linux::WindowOpenGL::shutdown()
{
	this->opengl_disable(this->display, &this->window);
}



void Hako::Linux::WindowOpenGL::process_events()
{
	//
	// Process all queued Linux event messages.
	//
	XEvent event;

	while(XPending(this->display))
	{
		XNextEvent(this->display, &event);

		switch (event.type)
		{

		}
	}

	//Render frame
	Hako::OpenGL::render(this->engine);
	glXSwapBuffers(this->display, this->window);
}



bool Hako::Linux::WindowOpenGL::did_user_quit()
{
	return this->user_quit;
}



void Hako::Linux::WindowOpenGL::opengl_enable(Display* display, ::Window* window)
{
	GLint		att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	GLXContext	glc;
	XVisualInfo	*vi;

	vi = glXChooseVisual(display, 0, att);

	glc = glXCreateContext(display, vi, NULL, GL_TRUE);
	glXMakeCurrent(display, *window, glc);
}



void Hako::Linux::WindowOpenGL::opengl_disable(Display* display, ::Window* window)
{
	// TODO: To be written.
}



#endif
