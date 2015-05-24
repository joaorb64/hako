#include "manager.h"



float Hako::Gfx::Manager_Generic::get_interpolation()
{
	return this->interpolation_factor;
}



void Hako::Gfx::Manager_Generic::set_interpolation(float interpolation_factor)
{
	this->interpolation_factor = interpolation_factor;
}
