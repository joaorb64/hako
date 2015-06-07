#ifndef HAKO_ENGINE_INPUT_MANAGER_H
#define HAKO_ENGINE_INPUT_MANAGER_H



#include <hako/common/math_vec.h>



namespace Hako
{
	namespace Input
	{
		enum class KeyCode : unsigned int
		{
			KeyboardStart,

			KeyboardSpace, KeyboardEnter,
			KeyboardArrowLeft, KeyboardArrowRight,
			KeyboardArrowUp, KeyboardArrowDown,

			KeyboardAlphabetStart,
			KeyboardA, KeyboardB, KeyboardC, KeyboardD, KeyboardE, KeyboardF,
			KeyboardG, KeyboardH, KeyboardI, KeyboardJ, KeyboardK, KeyboardL,
			KeyboardM, KeyboardN, KeyboardO, KeyboardP, KeyboardQ, KeyboardR,
			KeyboardS, KeyboardT, KeyboardU, KeyboardV, KeyboardW, KeyboardX,
			KeyboardY, KeyboardZ,
			KeyboardAlphabetEnd,

			KeyboardNumberStart,
			KeyboardNumber1, KeyboardNumber2, KeyboardNumber3, KeyboardNumber4,
			KeyboardNumber5, KeyboardNumber6, KeyboardNumber7, KeyboardNumber8,
			KeyboardNumber9, KeyboardNumber0,
			KeyboardNumberEnd,

			KeyboardEnd
		};


		class Request
		{
		public:
			KeyCode key_code;
		};


		class Manager_Generic
		{
			virtual bool  GetButton             (Hako::Input::Request* req) = 0;
			virtual float GetAxis1              (Hako::Input::Request* req) = 0;
			virtual Hako::Math::Vec<2> GetAxis2 (Hako::Input::Request* req) = 0;
			virtual Hako::Math::Vec<3> GetAxis3 (Hako::Input::Request* req) = 0;
			virtual void SetAxis1               (Hako::Input::Request* req, float x) = 0;
			virtual void SetAxis2               (Hako::Input::Request* req, float x, float y) = 0;
			virtual void SetAxis3               (Hako::Input::Request* req, float x, float y, float z) = 0;
		};
	}
}


#endif
