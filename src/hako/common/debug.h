#ifndef HAKO_COMMON_DEBUG_H
#define HAKO_COMMON_DEBUG_H


// Suppresses unused parameter warnings.
#define HAKO_UNUSED(varname) \
	(void)varname


#ifdef HAKO_BUILD_DEBUG


	// Removes statement from release builds.
	#define HAKO_ONLYINDEBUG(stat) \
		stat


	namespace Hako
	{
		void assert_handler(bool condition, const char* msg, const char* filename, int line);
	}


	// Runtime assert.
	#define HAKO_ASSERT(cond, msg) \
		do { Hako::assert_handler(cond, msg, __FILE__, __LINE__); } while (0)


	// Runtime error.
	#define HAKO_ERROR(msg) \
		HAKO_ASSERT(false, msg)


#else
	#define HAKO_ONLYINDEBUG(stat)
	#define HAKO_ASSERT(cond, msg) do { } while (0)
	#define HAKO_ERROR(msg) do { } while (0)
#endif

#endif
