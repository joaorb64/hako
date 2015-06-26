#ifdef HAKO_BUILD_DEBUG


#include "debug.h"
#include <stdlib.h>
#include <stdio.h>


void Hako::assert_handler(bool condition, const char* msg, const char* filename, int line)
{
	if (!condition)
	{
		// A breakpoint may be set here to debug the callstack, for example.
		printf("HAKO ASSERT FAILED: %s\nFILE: %s\nLINE: %d\n", msg, filename, line);
		abort();
	}
}


#endif
