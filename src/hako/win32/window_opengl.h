#ifdef HAKO_PLATFORM_WIN32


#ifndef HAKO_WIN32_WINDOW_OPENGL_H
#define HAKO_WIN32_WINDOW_OPENGL_H


#include "window.h"
#include <windows.h>


namespace Hako
{
	namespace Win32
	{
		class WindowOpenGL : public Hako::Win32::Window
		{
		public:
			void init           (Hako::Engine* engine) override;
			void shutdown       () override;
			void process_events () override;

			bool did_user_quit  () override;

			// OpenGL render task.
			void render (Hako::Engine* engine) override;


		protected:
			// Win32 handle to the main window.
			HWND   hwnd;
			// Win32 handles to the renderer context.
			HDC    hdc;
			HGLRC  hrc;
			// Flag for whether the user closed the window.
			bool   user_quit;


			// Window callback function used by Win32.
			static LRESULT CALLBACK window_callback(
				HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

			// Win32 OpenGL setup.
			void opengl_enable  (HWND hwnd, HDC* hdc, HGLRC* hrc);
			void opengl_disable (HWND hwnd, HDC  hdc, HGLRC  hrc);
		};
	}
}


#endif


#endif

