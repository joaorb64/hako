#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_LINUX_GFX_H
#define HAKO_LINUX_GFX_H


namespace Hako
{
	namespace Linux
	{
		class WindowGfx
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

