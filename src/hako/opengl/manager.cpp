#ifdef HAKO_BUILD_GFXOPENGL


#include "manager.h"
#include <hako/engine/engine.h>


void Hako::Gfx::Manager_OpenGL::init(Hako::Engine* engine)
{
	this->commandlists.init(engine->get_mem_callbacks(), 0);
}



void Hako::Gfx::Manager_OpenGL::commandlist_add(Hako::Gfx::CommandList_Generic* commandlist)
{
	this->commandlists.add(commandlist);
}


#endif
