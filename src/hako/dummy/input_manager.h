#ifndef HAKO_DUMMY_INPUT_MANAGER_H
#define HAKO_DUMMY_INPUT_MANAGER_H


#include <hako/engine/input/request.h>
#include <hako/common/debug.h>


namespace Hako
{
	namespace Dummy
	{
		class Input_Manager
		{
		public:
			bool               GetButton(Hako::Input::Request* req) { HAKO_UNUSED(req); return false; }
			float              GetAxis1 (Hako::Input::Request* req) { HAKO_UNUSED(req); return 0.0f; }
			Hako::Math::Vec<2> GetAxis2 (Hako::Input::Request* req) { HAKO_UNUSED(req); return Hako::Math::Vec<2>(); }
			Hako::Math::Vec<3> GetAxis3 (Hako::Input::Request* req) { HAKO_UNUSED(req); return Hako::Math::Vec<3>(); }

			void SetAxis1(Hako::Input::Request* req, float x)
			{
				HAKO_UNUSED(req);
				HAKO_UNUSED(x);
			}

			void SetAxis2(Hako::Input::Request* req, float x, float y)
			{
				HAKO_UNUSED(req);
				HAKO_UNUSED(x);
				HAKO_UNUSED(y);
			}

			void SetAxis3(Hako::Input::Request* req, float x, float y, float z)
			{
				HAKO_UNUSED(req);
				HAKO_UNUSED(x);
				HAKO_UNUSED(y);
				HAKO_UNUSED(z);
			}
		};
	}
}


#endif
