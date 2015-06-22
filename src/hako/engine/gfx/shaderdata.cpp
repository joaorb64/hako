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
	this->outputs   .init(engine->get_mem_callbacks(), 0);

	this->data   = nullptr;
	this->length = 0;
}



void Hako::Gfx::ShaderData::add_attribute(Hako::Gfx::DataFormat format, int position, Hako::String name)
{
	Hako::Gfx::ShaderData::Buffer attrib;
	attrib.format   = format;
	attrib.position = position;
	attrib.name     = name;
	this->attributes.add(attrib);
}



void Hako::Gfx::ShaderData::add_uniform(Hako::Gfx::DataFormat format, int position, Hako::String name)
{
	Hako::Gfx::ShaderData::Buffer unif;
	unif.format   = format;
	unif.position = position;
	unif.name     = name;
	this->uniforms.add(unif);
}



void Hako::Gfx::ShaderData::add_output(Hako::Gfx::DataFormat format, int position, Hako::String name)
{
	Hako::Gfx::ShaderData::Buffer outp;
	outp.format   = format;
	outp.position = position;
	outp.name     = name;
	this->outputs.add(outp);
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
