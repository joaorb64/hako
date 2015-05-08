#ifndef HAKO_BASE_APP_H
#define HAKO_BASE_APP_H


#include "../common/options.h"


namespace HakoInternal
{
	namespace Base
	{
		class App
		{
		public:
			virtual int init      (Hako::Options* options) = 0;
			virtual int main_loop (Hako::Options* options) = 0;
		};
	}
}


#endif
