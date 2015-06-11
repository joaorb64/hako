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

	this->attribute_slots       .init(engine->get_mem_callbacks(), 0);
	this->uniform_float_slots   .init(engine->get_mem_callbacks(), 0);
	this->uniform_float2_slots  .init(engine->get_mem_callbacks(), 0);
	this->uniform_float3_slots  .init(engine->get_mem_callbacks(), 0);
	this->uniform_float4_slots  .init(engine->get_mem_callbacks(), 0);
	this->uniform_matrix4_slots .init(engine->get_mem_callbacks(), 0);
	this->uniform_texture_slots .init(engine->get_mem_callbacks(), 0);
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
	unsigned int float_slots = 0;
	unsigned int float2_slots = 0;
	unsigned int float3_slots = 0;
	unsigned int float4_slots = 0;
	unsigned int matrix4_slots = 0;
	unsigned int texture_slots = 0;

	for (unsigned int i = 0; i < this->vertex_shader->uniforms.get_length(); i++)
	{
		switch (this->vertex_shader->uniforms.get_element(i).type)
		{
			case Hako::Gfx::ShaderData::Uniform::Type::Float:   float_slots++;   break;
			case Hako::Gfx::ShaderData::Uniform::Type::Float2:  float2_slots++;  break;
			case Hako::Gfx::ShaderData::Uniform::Type::Float3:  float3_slots++;  break;
			case Hako::Gfx::ShaderData::Uniform::Type::Float4:  float4_slots++;  break;
			case Hako::Gfx::ShaderData::Uniform::Type::Matrix4: matrix4_slots++; break;
			case Hako::Gfx::ShaderData::Uniform::Type::Texture: texture_slots++; break;
		}
	}

	for (unsigned int i = 0; i < this->pixel_shader->uniforms.get_length(); i++)
	{
		switch (this->pixel_shader->uniforms.get_element(i).type)
		{
			case Hako::Gfx::ShaderData::Uniform::Type::Float:   float_slots++;   break;
			case Hako::Gfx::ShaderData::Uniform::Type::Float2:  float2_slots++;  break;
			case Hako::Gfx::ShaderData::Uniform::Type::Float3:  float3_slots++;  break;
			case Hako::Gfx::ShaderData::Uniform::Type::Float4:  float4_slots++;  break;
			case Hako::Gfx::ShaderData::Uniform::Type::Matrix4: matrix4_slots++; break;
			case Hako::Gfx::ShaderData::Uniform::Type::Texture: texture_slots++; break;
		}
	}

	this->uniform_float_slots   .ensure_capacity(float_slots);
	this->uniform_float2_slots  .ensure_capacity(float2_slots);
	this->uniform_float3_slots  .ensure_capacity(float3_slots);
	this->uniform_float4_slots  .ensure_capacity(float4_slots);
	this->uniform_matrix4_slots .ensure_capacity(matrix4_slots);
	this->uniform_texture_slots .ensure_capacity(texture_slots);

	for (unsigned int i = 0; i < this->vertex_shader->uniforms.get_length(); i++)
		this->add_slot(&this->vertex_shader->uniforms.get_element(i));

	for (unsigned int i = 0; i < this->pixel_shader->uniforms.get_length(); i++)
		this->add_slot(&this->pixel_shader->uniforms.get_element(i));

	this->attribute_slots.set_length(this->vertex_shader->attributes.get_length());
	for (unsigned int i = 0; i < this->vertex_shader->attributes.get_length(); i++)
	{
		GLint attrb_loc = glGetAttribLocation(this->gl_program, this->vertex_shader->attributes.get_element(i).name->get_c_str());
		HAKO_ASSERT(attrb_loc >= 0, "unable to get OpenGL shader attribute location");
		this->attribute_slots.get_element(i) = attrb_loc;
	}

	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Material::add_slot(Hako::Gfx::ShaderData::Uniform* uniform)
{
	switch (uniform->type)
	{
		case Hako::Gfx::ShaderData::Uniform::Type::Float:
		{
			this->uniform_float_slots.add(glGetUniformLocation(this->gl_program, uniform->name->get_c_str()));
			break;
		}
		case Hako::Gfx::ShaderData::Uniform::Type::Float2:
		{
			this->uniform_float2_slots.add(glGetUniformLocation(this->gl_program, uniform->name->get_c_str()));
			break;
		}
		case Hako::Gfx::ShaderData::Uniform::Type::Float3:
		{
			this->uniform_float3_slots.add(glGetUniformLocation(this->gl_program, uniform->name->get_c_str()));
			break;
		}
		case Hako::Gfx::ShaderData::Uniform::Type::Float4:
		{
			this->uniform_float4_slots.add(glGetUniformLocation(this->gl_program, uniform->name->get_c_str()));
			break;
		}
		case Hako::Gfx::ShaderData::Uniform::Type::Matrix4:
		{
			this->uniform_matrix4_slots.add(glGetUniformLocation(this->gl_program, uniform->name->get_c_str()));
			break;
		}
		case Hako::Gfx::ShaderData::Uniform::Type::Texture:
		{
			this->uniform_texture_slots.add(glGetUniformLocation(this->gl_program, uniform->name->get_c_str()));
			break;
		}
	}
}



int Hako::OpenGL::Material::get_float_slot(Hako::String* name)
{
	// To be written.
	HAKO_UNUSED(name);
	return 0;
}



int Hako::OpenGL::Material::get_float2_slot(Hako::String* name)
{
	// To be written.
	HAKO_UNUSED(name);
	return 0;
}



int Hako::OpenGL::Material::get_float3_slot(Hako::String* name)
{
	// To be written.
	HAKO_UNUSED(name);
	return 0;
}



int Hako::OpenGL::Material::get_float4_slot(Hako::String* name)
{
	// To be written.
	HAKO_UNUSED(name);
	return 0;
}



int Hako::OpenGL::Material::get_matrix4_slot(Hako::String* name)
{
	// To be written.
	HAKO_UNUSED(name);
	return 0;
}



int Hako::OpenGL::Material::get_texture_slot(Hako::String* name)
{
	// To be written.
	HAKO_UNUSED(name);
	return 0;
}



#endif
