#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_LINUX_WINDOW_OPENGL_H
#define HAKO_LINUX_WINDOW_OPENGL_H


#include "window.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glx.h>

namespace Hako
{
	namespace Linux
	{
		class WindowOpenGL : public Hako::Linux::Window
		{
		public:
			void init           (Hako::Engine* engine) override;
			void shutdown       () override;
			void process_events () override;

			bool did_user_quit  () override;


		protected:
			// Reference to the engine instance.
			Hako::Engine* engine;

			// Handle to the main window.
			::Window   window;

			//Handle to the display.
			Display* display;

			// Flag for whether the user closed the window.
			bool     user_quit;


			// Linux OpenGL setup.
			void opengl_enable  (Display* display, ::Window* window);
			void opengl_disable (Display* display, ::Window* window);
		};
	}
}


#endif


#endif

