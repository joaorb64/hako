#ifdef HAKO_BUILD_WIN32


#ifndef HAKO_WIN32_APP_H
#define HAKO_WIN32_APP_H


#include "../base/app.h"


namespace HakoInternal
{
	namespace Win32
	{
		class App : public Base::App
		{
		public:
			int init      (Hako::Options* options) override { /* stub */ return 0; };
			int main_loop (Hako::Options* options) override { /* stub */ return 0; };
		};
	}
}


#endif


#endif
