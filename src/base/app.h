#ifndef HAKO_BASE_APP_H
#define HAKO_BASE_APP_H


namespace HakoInternal
{
	namespace Base
	{
		class App
		{
		public:
			virtual int Init() = 0;
			virtual int MainLoop() = 0;
		};
	}
}


#endif
