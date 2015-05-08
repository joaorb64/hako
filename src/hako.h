#ifndef HAKO_H
#define HAKO_H


#include "common/options.h"


#ifdef HAKO_BUILD_WIN32

	#include "win32/app.h"

	namespace Hako
	{
		typedef HakoInternal::Win32::App App;
	}


#elif HAKO_BUILD_LINUX

    #include "linux/app.h"

	namespace Hako
	{
		typedef HakoInternal::Linux::App App;
	}

#endif


#endif
