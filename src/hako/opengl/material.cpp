#ifdef HAKO_MODULE_OPENGL


#include "material.h"
#include <hako/engine/engine.h>
#include <hako/common/string.h>
#include <stdio.h>



int opengl_compile_shader(void* data, GLuint type, GLuint* id)
{
	*id = glCreateShader(type);
	glShaderSource(*id, 1, (char**)&data, NULL);
	glCompileShader(*id);
	GLint compiled;
	glGetShaderiv(*id, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		GLint length;
		//glGetShaderiv(*id, GL_INFO_LOG_LENGTH, &length);
		char log[1024];
		glGetShaderInfoLog(*id, 1024, &length, log);
		printf("shader error:\n%s\n", log);
		HAKO_ERROR("could not compile OpenGL shader");
		return -1;
	}
	HAKO_OPENGL_CHECKERROR();
	return 0;
}



void Hako::OpenGL::Material::init(Hako::Engine* engine)
{
	this->engine = engine;
	this->vertex_shader = nullptr;
	this->pixel_shader  = nullptr;
	this->ztest         = Hako::Gfx::MaterialZTest::AlwaysPass;

	for (unsigned int i = 0; i < (unsigned int)Hako::Gfx::DataFormat::Last; i++)
	{
		this->data_slots[i].init(engine->get_mem_callbacks(), 0);
		this->data_maps [i].init(engine->get_mem_callbacks(), 0);
	}

	this->attribute_slots.init(engine->get_mem_callbacks(), 0);
}



void Hako::OpenGL::Material::set_shaders(Hako::Gfx::ShaderData* vertex_shader, Hako::Gfx::ShaderData* pixel_shader)
{
	this->vertex_shader = vertex_shader;
	this->pixel_shader  = pixel_shader;
}



void Hako::OpenGL::Material::set_ztest(Hako::Gfx::MaterialZTest ztest)
{
	this->ztest = ztest;
}



void Hako::OpenGL::Material::finish()
{
	//
	// Compile OpenGL shaders into a program.
	//
	this->gl_program = glCreateProgram();

	opengl_compile_shader(this->vertex_shader->data, GL_VERTEX_SHADER, &this->gl_vertex_shader);
	glAttachShader(this->gl_program, this->gl_vertex_shader);

	opengl_compile_shader(this->pixel_shader->data, GL_FRAGMENT_SHADER, &this->gl_pixel_shader);
	glAttachShader(this->gl_program, this->gl_pixel_shader);

	glBindFragDataLocation(this->gl_program, 0, "color");

	glLinkProgram(this->gl_program);
	glUseProgram(this->gl_program);

	//
	// Prepare uniform slots.
	//
	unsigned int data_slot_num[(unsigned int)Hako::Gfx::DataFormat::Last] = { 0 };

	for (unsigned int i = 0; i < this->vertex_shader->uniforms.get_length(); i++)
		data_slot_num[(unsigned int)this->vertex_shader->uniforms[i].format]++;

	for (unsigned int i = 0; i < this->pixel_shader->uniforms.get_length(); i++)
		data_slot_num[(unsigned int)this->pixel_shader->uniforms[i].format]++;

	for (unsigned int i = 0; i < (unsigned int)Hako::Gfx::DataFormat::Last; i++)
	{
		this->data_slots[i].ensure_capacity(data_slot_num[i]);
		this->data_maps [i].ensure_capacity(data_slot_num[i]);
	}

	for (unsigned int i = 0; i < this->vertex_shader->uniforms.get_length(); i++)
		this->add_slot(&this->vertex_shader->uniforms[i]);

	for (unsigned int i = 0; i < this->pixel_shader->uniforms.get_length(); i++)
		this->add_slot(&this->pixel_shader->uniforms[i]);

	//
	// Prepare attribute slots.
	//
	this->attribute_slots.set_length(this->vertex_shader->attributes.get_length());
	for (unsigned int i = 0; i < this->vertex_shader->attributes.get_length(); i++)
	{
		GLint attrb_loc = glGetAttribLocation(this->gl_program, this->vertex_shader->attributes[i].name.get_c_str());
		HAKO_ASSERT(attrb_loc >= 0, "unable to get OpenGL shader attribute location");
		this->attribute_slots[i] = attrb_loc;
	}

	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Material::add_slot(Hako::Gfx::ShaderData::Buffer* uniform)
{
	GLint unif_loc = glGetUniformLocation(this->gl_program, uniform->name.get_c_str());
	HAKO_ASSERT(unif_loc >= 0, "unable to get OpenGL shader uniform location");

	unsigned int index = this->data_slots[(unsigned int)uniform->format].add(unif_loc);

	this->data_maps[(unsigned int)uniform->format].add(uniform->name, index);
}



int Hako::OpenGL::Material::get_uniform_slot(Hako::Gfx::DataFormat format, Hako::String name)
{
	return this->data_maps[(unsigned int)format].access(name);
}



#endif
