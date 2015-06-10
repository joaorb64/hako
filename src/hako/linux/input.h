#ifdef HAKO_PLATFORM_LINUX

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <hako/engine/input/manager.h>

namespace Hako
{
	namespace Input
	{
		class Manager_Linux : public Manager_Generic
		{
			bool GetKey(Input_Request::InputCode code);
			float GetAxis1(Input_Request::InputCode axis);
		};
	}
}

#endif // INPUT_H_INCLUDED

#endif // HAKO_PLATFORM_LINUX
