#ifndef HAKO_BASE_APP_H
#define HAKO_BASE_APP_H


#include "../common/options.h"


namespace HakoInternal
{
	namespace Base
	{
		// The common base class that defines the interface to the
		// application process initialization and execution.
		class App
		{
		public:

			// Initializes the application with the given options.
			virtual int init      (Hako::Options* options) = 0;


			// Runs the application's main loop, handling system and user-
			// interface events.
			virtual int main_loop (Hako::Options* options) = 0;
		};
	}
}


#endif
