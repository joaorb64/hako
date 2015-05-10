#ifdef HAKO_BUILD_WIN32


#ifndef HAKO_WIN32_APP_H
#define HAKO_WIN32_APP_H


#include "../base/app.h"
#include <windows.h>


namespace HakoInternal
{
	class Win32App : public Base::App
	{
	public:
		int init      (Hako::Options* options) override;
		int main_loop (Hako::Options* options) override;

	protected:
		// A Win32 handle to the main window.
		HWND   m_hwnd_main;

		// Win32 handles to the renderer context.
		HDC    m_hdc;
		HGLRC  m_hrc;
	};
}


#endif


#endif
