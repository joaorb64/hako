#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_LINUX_GFX_OPENGL_H
#define HAKO_LINUX_GFX_OPENGL_H


#include "gfx.h"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


namespace Hako
{
	namespace Linux
	{
		class WindowGfxOpenGL : public Hako::Linux::WindowGfx
		{
		public:
			void init           (Hako::Engine* engine) override;
			void shutdown       () override;
			void process_events () override;

			bool did_user_quit  () override;


		protected:
			// Reference to the engine instance.
			Hako::Engine* m_engine;

			// Handle to the main window.
			Window   m_window;

			//Handle to the display.
			Display* m_display;

			// Flag for whether the user closed the window.
			bool   m_user_quit;


			// Linux OpenGL setup.
			void opengl_enable  (Display* display, Window* window);
			void opengl_disable (Display* display, Window* window);
		};
	}
}


#endif


#endif

