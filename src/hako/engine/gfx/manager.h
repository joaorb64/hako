#ifndef HAKO_ENGINE_GFX_GFX_H
#define HAKO_ENGINE_GFX_GFX_H


namespace Hako
{
	namespace Gfx
	{
		class Manager_Generic
		{
		public:
			float get_interpolation ();
			void set_interpolation  (float interpolation_factor);

		protected:
			float interpolation_factor;
		};
	}
}


#endif



