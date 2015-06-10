#ifdef HAKO_MODULE_OPENGL


#include "manager.h"
#include <hako/engine/engine.h>


void Hako::OpenGL::Manager::init(Hako::Engine* engine)
{
	this->commandlists.init(engine->get_mem_callbacks(), 0);
}



void Hako::OpenGL::Manager::commandlist_add(Hako::OpenGL::CommandList* commandlist)
{
	this->commandlists.add(commandlist);
}


#endif
