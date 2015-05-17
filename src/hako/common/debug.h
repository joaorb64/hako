#ifndef HAKO_COMMON_DEBUG_H
#define HAKO_COMMON_DEBUG_H


#include <stdlib.h>
#include <stdio.h>


// Suppresses unused parameter warnings.
#define HAKO_UNUSED(varname) \
	(void)varname


#ifdef HAKO_BUILD_DEBUG


	// Removes statement from release builds.
	#define HAKO_ONLYINDEBUG(stat) \
		stat


	// Runtime assert.
	#define HAKO_ASSERT(cond, msg) \
		do { if (!cond) { printf("ASSERT FAILED: " msg "\nFILE: " __FILE__ "\nLINE: %u\n", __LINE__); abort(); } } while (0)


	// Runtime error.
	#define HAKO_ERROR(msg) \
		HAKO_ASSERT(false, msg)


#else
	#define HAKO_ONLYINDEBUG(stat)
	#define HAKO_ASSERT(cond, msg) do { } while (0)
	#define HAKO_ERROR(msg) do { } while (0)
#endif

#endif
