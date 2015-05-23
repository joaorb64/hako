#ifndef HAKO_COMMON_GFX_H
#define HAKO_COMMON_GFX_H


#include <hako/common/debug.h>


namespace Hako
{
	class Engine;


	class Gfx
	{
	public:
		virtual void init (Hako::Engine* engine) { HAKO_UNUSED(engine); /* do nothing */ }

		virtual void shutdown       () { /* do nothing */ }
		virtual void process_events () { /* do nothing */ }

		virtual bool did_user_quit  () { return false; }
	};
}


#endif



