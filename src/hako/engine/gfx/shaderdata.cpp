#include "shaderdata.h"
#include <hako/engine/engine.h>



Hako::Gfx::ShaderData::~ShaderData()
{
	// Do nothing.
}



void Hako::Gfx::ShaderData::init(Hako::Engine* engine)
{
	this->attributes.init(engine->get_mem_callbacks(), 0);
	this->uniforms  .init(engine->get_mem_callbacks(), 0);

	this->data   = nullptr;
	this->length = 0;
}



void Hako::Gfx::ShaderData::add_attribute(Attribute::Format format, int position)
{
	Attribute attrib;
	attrib.format   = format;
	attrib.position = position;
	this->attributes.add(attrib);
}



void Hako::Gfx::ShaderData::add_uniform(Uniform::Type type, int position, Hako::String* name)
{
	Uniform unif;
	unif.type     = type;
	unif.position = position;
	unif.name     = name;
	this->uniforms.add(unif);
}



void Hako::Gfx::ShaderData::set_program_data(void* data, unsigned int length)
{
	this->data   = data;
	this->length = length;
}



void Hako::Gfx::ShaderData::finish()
{
	// Do nothing.
}
