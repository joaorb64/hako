#ifndef HAKO_ENGINE_APP_H
#define HAKO_ENGINE_APP_H



namespace Hako
{
	class Engine;

	namespace App
	{
		void on_startup (void** userdata, Hako::Engine* engine);
		void on_ready   (void*  userdata, Hako::Engine* engine);
	}
}



#endif
