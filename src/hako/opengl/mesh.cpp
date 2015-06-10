#ifdef HAKO_BUILD_GFXOPENGL


#include "mesh.h"
#include "gl_includes.h"
#include <hako/engine/engine.h>



Hako::OpenGL::Mesh::~Mesh()
{
	this->engine->get_mem_callbacks().free_callback.call(this->attrib_formats);
	this->engine->get_mem_callbacks().free_callback.call(this->gl_data_buffers);
}



void Hako::OpenGL::Mesh::init(
	Hako::Engine*                   engine,
	unsigned int                    attrib_number,
	Hako::Gfx::MeshAttributeFormat* attrib_formats,
	unsigned int                    vertex_number,
	unsigned int                    index_number)
{
	this->engine         = engine;
	this->attrib_number  = attrib_number;
	this->attrib_formats = attrib_formats;
	this->vertex_number  = vertex_number;
	this->index_number   = index_number;

	glGenVertexArrays(1, &this->gl_vertex_array_object);
	glBindVertexArray(this->gl_vertex_array_object);

	//
	// Copy attribute formats over.
	//
	this->attrib_formats = (Hako::Gfx::MeshAttributeFormat*)
		engine->get_mem_callbacks().alloc_callback.call(sizeof(Hako::Gfx::MeshAttributeFormat) * attrib_number, 32);
	HAKO_ASSERT(this->attrib_formats, "unable to allocate mesh data format array");

	for (unsigned int i = 0; i < attrib_number; i++)
		this->attrib_formats[i] = attrib_formats[i];

	//
	// Generate a buffer for each attribute.
	//
	this->gl_data_buffers = (GLuint*)
		engine->get_mem_callbacks().alloc_callback.call(sizeof(GLuint) * attrib_number, 32);
	HAKO_ASSERT(this->gl_data_buffers, "unable to allocate mesh data buffer index array");

	//
	// Generate a buffer for indices.
	//
	glGenBuffers(attrib_number, this->gl_data_buffers);
	glGenBuffers(1, &this->gl_index_buffer);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Mesh::set_data_float(unsigned int attrib_index, float* data)
{
	HAKO_ASSERT(attrib_index < this->attrib_number, "attrib_index out of bounds");
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_data_buffers[attrib_index]);
	glBufferData(GL_ARRAY_BUFFER, this->vertex_number * 1 * 4, data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Mesh::set_data_float2(unsigned int attrib_index, float* data)
{
	HAKO_ASSERT(attrib_index < this->attrib_number, "attrib_index out of bounds");
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_data_buffers[attrib_index]);
	glBufferData(GL_ARRAY_BUFFER, this->vertex_number * 2 * 4, data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Mesh::set_data_float3(unsigned int attrib_index, float* data)
{
	HAKO_ASSERT(attrib_index < this->attrib_number, "attrib_index out of bounds");
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_data_buffers[attrib_index]);
	glBufferData(GL_ARRAY_BUFFER, this->vertex_number * 3 * 4, data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Mesh::set_data_float4(unsigned int attrib_index, float* data)
{
	HAKO_ASSERT(attrib_index < this->attrib_number, "attrib_index out of bounds");
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_data_buffers[attrib_index]);
	glBufferData(GL_ARRAY_BUFFER, this->vertex_number * 4 * 4, data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Mesh::set_indices(unsigned int* indices)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->gl_index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->index_number * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::Mesh::finish()
{
	// Do nothing.
}


#endif
