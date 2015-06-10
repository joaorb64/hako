#ifdef HAKO_BUILD_GFXOPENGL


#include "commandlist.h"
#include <hako/engine/engine.h>


Hako::OpenGL::CommandList::~CommandList()
{

}



void Hako::OpenGL::CommandList::init(Hako::Engine* engine)
{
	this->commands.init(engine->get_mem_callbacks(), 0);
}



void Hako::OpenGL::CommandList::clear()
{
	this->commands.set_length(0);
}



void Hako::OpenGL::CommandList::begin()
{
	this->commands.set_length(0);
}



void Hako::OpenGL::CommandList::set_material(Hako::OpenGL::Material* material)
{
	Command command;
	command.kind = Command::Kind::SetMaterial;
	command.command_data.material = material;
	this->commands.add(command);
}



void Hako::OpenGL::CommandList::draw(Hako::OpenGL::Mesh* mesh)
{
	Command command;
	command.kind = Command::Kind::Draw;
	command.command_data.mesh = mesh;
	this->commands.add(command);
}



void Hako::OpenGL::CommandList::finish()
{

}


#endif
