#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_LINUX_APP_H
#define HAKO_LINUX_APP_H


#include "../base/app.h"


namespace HakoInternal
{
	namespace Linux
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
