#ifndef HAKO_ENGINE_GFX_MANAGER_H
#define HAKO_ENGINE_GFX_MANAGER_H


#include <hako/engine/abstract_bindings.h>


namespace Hako
{
	namespace Gfx
	{
		class Manager_Generic
		{
		public:
			float get_interpolation ();
			void set_interpolation  (float interpolation_factor);

			virtual void commandlist_add(Hako::Gfx::CommandList_Generic* commandlist) = 0;

		protected:
			float interpolation_factor;
		};
	}
}


#endif



