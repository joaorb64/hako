#ifdef HAKO_BUILD_WIN32


#ifndef HAKO_WIN32_GFX_H
#define HAKO_WIN32_GFX_H


#include <hako/common/gfx.h>
#include <windows.h>


namespace Hako
{
	namespace Win32
	{
		class GfxOpenGL : public Hako::Gfx
		{
		public:
			void init           (Hako::Engine* engine) override;
			void shutdown       () override;
			void process_events () override;

			bool did_user_quit  () override;


		protected:
			// Win32 handle to the main window.
			HWND   m_hwnd;
			// Win32 handles to the renderer context.
			HDC    m_hdc;
			HGLRC  m_hrc;
			// Flag for whether the user closed the window.
			bool   m_user_quit;


			// Window callback function used by Win32.
			static LRESULT CALLBACK window_callback(
				HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

			// Win32 OpenGL setup.
			void opengl_enable  (HWND hwnd, HDC* hdc, HGLRC* hrc);
			void opengl_disable (HWND hwnd, HDC  hdc, HGLRC  hrc);

			// OpenGL render task.
			static void render (void* gfx, Hako::Engine* engine);
		};
	}
}


#endif


#endif

