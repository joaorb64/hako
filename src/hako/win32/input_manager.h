#ifdef HAKO_PLATFORM_WIN32


#ifndef HAKO_WIN32_INPUT_MANAGER_H
#define HAKO_WIN32_INPUT_MANAGER_H


#include <hako/engine/input/request.h>
#include <windows.h>


namespace Hako
{
	class Engine;


	namespace Win32
	{
		class Input_Manager
		{
		public:
			void init    (Hako::Engine* engine);
			void process ();

			bool               GetButton(Hako::Input::Request* req);
			float              GetAxis1 (Hako::Input::Request* req);
			Hako::Math::Vec<2> GetAxis2 (Hako::Input::Request* req);
			Hako::Math::Vec<3> GetAxis3 (Hako::Input::Request* req);
			void               SetAxis1 (Hako::Input::Request* req, float x);
			void               SetAxis2 (Hako::Input::Request* req, float x, float y);
			void               SetAxis3 (Hako::Input::Request* req, float x, float y, float z);


		protected:
			BYTE keyboard_state[2][256];
			int  current_keyboard_buffer;

			int translate_keyboard_code(Hako::Input::KeyCode code);
		};
	}
}



#endif


#endif
