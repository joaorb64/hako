#ifndef HAKO_ENGINE_INPUT_MANAGER_H
#define HAKO_ENGINE_INPUT_MANAGER_H

#include <hako/engine/input/input_request.h>

namespace Hako
{
	namespace Input
	{
		class Manager_Generic
		{
			virtual bool GetKey(Input_Request::InputCode code) = 0;
			virtual float GetAxis1(Input_Request::InputCode axis) = 0;
			//vec2 GetAxis2();
		};
	}
}


#endif // HAKO_ENGINE_INPUT_MANAGER_H
