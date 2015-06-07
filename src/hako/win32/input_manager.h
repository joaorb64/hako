#ifdef HAKO_BUILD_WIN32


#ifndef HAKO_WIN32_INPUT_MANAGER_H
#define HAKO_WIN32_INPUT_MANAGER_H


#include <hako/engine/input/manager.h>
#include <windows.h>


namespace Hako
{
	namespace Input
	{
		class Manager_Win32 : public Manager_Generic
		{
		public:
			void init();
			void process();

			bool  GetButton             (Hako::Input::Request* req) override;
			float GetAxis1              (Hako::Input::Request* req) override;
			Hako::Math::Vec<2> GetAxis2 (Hako::Input::Request* req) override;
			Hako::Math::Vec<3> GetAxis3 (Hako::Input::Request* req) override;
			void SetAxis1               (Hako::Input::Request* req, float x) override;
			void SetAxis2               (Hako::Input::Request* req, float x, float y) override;
			void SetAxis3               (Hako::Input::Request* req, float x, float y, float z) override;


		protected:
			BYTE keyboard_state[2][256];
			int  current_keyboard_buffer;

			int translate_keyboard_code(Hako::Input::KeyCode code);
		};
	}
}



#endif


#endif
