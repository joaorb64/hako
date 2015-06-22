#include "debug.h"
#include <stdlib.h>
#include <stdio.h>


void Hako::assert_handler(bool condition, const char* msg, const char* filename, int line)
{
	if (!condition)
	{
		printf("HAKO ASSERT FAILED: %s\nFILE: %s\nLINE: %d\n", msg, filename, line);
		abort();
	}
}
