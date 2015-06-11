#ifdef HAKO_MODULE_OPENGL


#include "vertex.h"
#include "gl_includes.h"
#include <hako/engine/engine.h>



Hako::OpenGL::VertexBuffer::~VertexBuffer()
{

}



void Hako::OpenGL::VertexBuffer::init(
	Hako::Engine* engine,
	Hako::Gfx::BufferFormat format,
	unsigned int vertex_number)
{
	HAKO_UNUSED(engine);
	this->buffer_format  = format;
	this->vertex_number  = vertex_number;

	//
	// Generate an OpenGL buffer.
	//
	glGenBuffers(1, &this->gl_buffer);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::VertexBuffer::set_data(unsigned int start_vertex, unsigned int length, float* data)
{
	HAKO_ASSERT(start_vertex + length <= this->vertex_number, "some vertices are out of the buffer's bounds");
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_buffer);
	glBufferData(GL_ARRAY_BUFFER, this->vertex_number * 1 * 4, data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::VertexBuffer::finish()
{
	// Do nothing.
}





Hako::OpenGL::IndexBuffer::~IndexBuffer()
{

}



void Hako::OpenGL::IndexBuffer::init(Hako::Engine* engine, unsigned int index_number)
{
	HAKO_UNUSED(engine);
	this->index_number  = index_number;

	//
	// Generate an OpenGL buffer.
	//
	glGenBuffers(1, &this->gl_buffer);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::IndexBuffer::set_data(unsigned int start_index, unsigned int length, unsigned int* data)
{
	HAKO_ASSERT(start_index + length <= this->index_number, "some indices are out of the buffer's bounds");
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->gl_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->index_number * sizeof(unsigned int), data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::IndexBuffer::finish()
{
	// Do nothing.
}



#endif
