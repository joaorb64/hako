#ifdef HAKO_PLATFORM_WIN32


#ifndef HAKO_WIN32_WINDOW_H
#define HAKO_WIN32_WINDOW_H


namespace Hako
{
	class Engine;


	namespace Win32
	{
		class Window
		{
		public:
			virtual void init           (Hako::Engine* engine) = 0;
			virtual void shutdown       () = 0;
			virtual void process_events () = 0;

			virtual bool did_user_quit  () = 0;
		};
	}
}


#endif


#endif

