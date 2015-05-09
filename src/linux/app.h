#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_LINUX_APP_H
#define HAKO_LINUX_APP_H


#include "../base/app.h"
#include <stdio.h>
#include <X11/Xlib.h>
#include <string.h>


namespace HakoInternal
{
	namespace Linux
	{
		class App : public Base::App
		{
		public:
			int init      (Hako::Options* options) override;
			int main_loop (Hako::Options* options) override;

        protected:
            Display *display;
		};
	}
}


#endif


#endif
