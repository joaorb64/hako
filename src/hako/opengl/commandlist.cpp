#ifdef HAKO_BUILD_GFXOPENGL


#include "commandlist.h"
#include <hako/engine/engine.h>


Hako::Gfx::CommandList_OpenGL::~CommandList_OpenGL()
{

}



void Hako::Gfx::CommandList_OpenGL::init(Hako::Engine* engine)
{
	this->commands.init(engine->get_mem_callbacks(), 0);
}



void Hako::Gfx::CommandList_OpenGL::clear()
{
	this->commands.set_length(0);
}



void Hako::Gfx::CommandList_OpenGL::begin()
{
	this->commands.set_length(0);
}



void Hako::Gfx::CommandList_OpenGL::set_material(Hako::Gfx::Material_Generic* material)
{
	Command command;
	command.kind = Command::Kind::SetMaterial;
	command.command_data.material = material;
	this->commands.add(command);
}



void Hako::Gfx::CommandList_OpenGL::draw(Hako::Gfx::Mesh_Generic* mesh)
{
	Command command;
	command.kind = Command::Kind::Draw;
	command.command_data.mesh = mesh;
	this->commands.add(command);
}



void Hako::Gfx::CommandList_OpenGL::finish()
{

}


#endif
