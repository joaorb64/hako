#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_LINUX_APP_H
#define HAKO_LINUX_APP_H


#include "../base/app.h"
#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>


namespace HakoInternal
{
	class LinuxApp : public Base::App
	{
	public:
		int init      (Hako::Options* options) override;
		int main_loop (Hako::Options* options) override;

	protected:

		Display* m_display;
		Window   m_window;
	};
}


#endif


#endif
