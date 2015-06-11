#ifdef HAKO_MODULE_OPENGL


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



void Hako::OpenGL::CommandList::set_vertex_buffer(unsigned int index, Hako::OpenGL::VertexBuffer* buffer)
{
	Command command;
	command.kind = Command::Kind::SetVertexBuffer;
	command.index = index;
	command.command_data.vertex_buffer = buffer;
	this->commands.add(command);
}



void Hako::OpenGL::CommandList::draw_indexed(Hako::OpenGL::IndexBuffer* buffer)
{
	Command command;
	command.kind = Command::Kind::DrawIndexed;
	command.command_data.index_buffer = buffer;
	this->commands.add(command);
}



void Hako::OpenGL::CommandList::finish()
{

}


#endif
