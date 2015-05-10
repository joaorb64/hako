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
	namespace Linux
	{
		class App : public Base::App
		{
		public:
			int init		(Hako::Options* options) override;
			int main_loop	(Hako::Options* options) override;

			void init_gl();
			void render_gl();

		protected:
			Display *display;
			Window window;
		};
	}
}


#endif


#endif
