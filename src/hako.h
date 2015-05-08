#ifndef HAKO_H
#define HAKO_H


#ifdef HAKO_BUILD_WIN32


	#include "win32/app.h"


	namespace Hako
	{
		typedef HakoInternal::Win32::App App;
	}


#endif


#endif
