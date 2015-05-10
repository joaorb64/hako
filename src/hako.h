#ifndef HAKO_H
#define HAKO_H


#include "common/options.h"


#ifdef HAKO_BUILD_WIN32

	#include "app_win32/app.h"

	namespace Hako
	{
		typedef HakoInternal::Win32App App;
	}


#elif HAKO_BUILD_LINUX

    #include "app_linux/app.h"

	namespace Hako
	{
		typedef HakoInternal::LinuxApp App;
	}

#endif


#endif
