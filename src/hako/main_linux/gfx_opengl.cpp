#ifdef HAKO_BUILD_LINUX


#include "gfx_opengl.h"
#include <hako/common/engine.h>


#ifdef HAKO_BUILD_GFXOPENGL
	#include <hako/common_gl/render.h>
#endif



void Hako::Linux::GfxOpenGL::init(Hako::Engine* engine)
{
	m_user_quit = false;

	m_display = XOpenDisplay(NULL);
	int screen = DefaultScreen(m_display);
	int depth = DefaultDepth(m_display, screen);

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

	opengl_enable(m_display, &m_window);

	//
	// Register render task.
	//
	Hako::Callback<void, Hako::Engine*> render_callback;
	render_callback.init(this, render);

	Hako::Task render_task;
	render_task.init(render_callback);

	engine->task_add_framesync(render_task);
}



void Hako::Linux::GfxOpenGL::shutdown()
{
	opengl_disable(m_display, &m_window);
}



void Hako::Linux::GfxOpenGL::process_events()
{
	//
	// Process all queued Linux event messages.
	//
	XEvent  event;

	while(XPending(m_display))
	{
		XNextEvent(m_display, &event);

		switch (event.type)
		{
			case Expose:
			{
				Hako::common_opengl_render();
				glXSwapBuffers(m_display, m_window);
				break;
			}
		}
	}
}



bool Hako::Linux::GfxOpenGL::did_user_quit()
{
	return m_user_quit;
}



void Hako::Linux::GfxOpenGL::window_callback()
{
	//TODO: Callback handling.
}



void Hako::Linux::GfxOpenGL::opengl_enable(Display* display, Window* window)
{
	GLint		att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	GLXContext	glc;
	XVisualInfo	*vi;

	vi = glXChooseVisual(display, 0, att);

	glc = glXCreateContext(display, vi, NULL, GL_TRUE);
	glXMakeCurrent(display, *window, glc);
}



void Hako::Linux::GfxOpenGL::opengl_disable(Display* display, Window* window)
{
	//TODO: To be written.
}



void Hako::Linux::GfxOpenGL::render(void* userdata, Hako::Engine* engine)
{
	HAKO_UNUSED(engine);
    Hako::Linux::GfxOpenGL* gfx = (Hako::Linux::GfxOpenGL*)userdata;

    Hako::common_opengl_render();
    glXSwapBuffers(gfx->m_display, gfx->m_window);
}



#endif
