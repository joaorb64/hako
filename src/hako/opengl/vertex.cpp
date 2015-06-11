#ifdef HAKO_MODULE_OPENGL


#include "vertex.h"
#include "gl_includes.h"
#include <hako/engine/engine.h>



Hako::OpenGL::VertexBuffer::VertexBuffer()
{
	HAKO_ONLYINDEBUG(this->init_called = false;)
	HAKO_ONLYINDEBUG(this->finish_called = false;)
}



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
	HAKO_ONLYINDEBUG(this->init_called = true;)
}



int Hako::OpenGL::get_format_element_num(Hako::Gfx::BufferFormat format)
{
	switch (format)
	{
		case Hako::Gfx::BufferFormat::Float:  return 1;
		case Hako::Gfx::BufferFormat::Float2: return 2;
		case Hako::Gfx::BufferFormat::Float3: return 3;
		case Hako::Gfx::BufferFormat::Float4: return 4;
	}
	return 0;
}



void Hako::OpenGL::VertexBuffer::set_data(unsigned int start_vertex, unsigned int length, float* data)
{
	HAKO_UNUSED(start_vertex);
	HAKO_ASSERT(start_vertex == 0 && length == this->vertex_number, "unimplemented");

	HAKO_ASSERT(this->init_called, "init() must be called first");
	HAKO_ASSERT(start_vertex + length <= this->vertex_number, "some vertices are out of the buffer's bounds");
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_buffer);
	glBufferData(GL_ARRAY_BUFFER, length * Hako::OpenGL::get_format_element_num(this->buffer_format) * 4, data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::VertexBuffer::finish()
{
	HAKO_ASSERT(this->init_called, "init() must be called first");
	// Do nothing.
}







Hako::OpenGL::IndexBuffer::IndexBuffer()
{
	HAKO_ONLYINDEBUG(this->init_called = false;)
	HAKO_ONLYINDEBUG(this->finish_called = false;)
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
	HAKO_ONLYINDEBUG(this->init_called = true;)
}



void Hako::OpenGL::IndexBuffer::set_data(unsigned int start_index, unsigned int length, unsigned int* data)
{
	HAKO_UNUSED(start_index);
	HAKO_ASSERT(start_index == 0 && length == this->index_number, "unimplemented");

	HAKO_ASSERT(this->init_called, "init() must be called first");
	HAKO_ASSERT(start_index + length <= this->index_number, "some indices are out of the buffer's bounds");
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->gl_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(unsigned int), data, GL_STATIC_DRAW);
	HAKO_OPENGL_CHECKERROR();
}



void Hako::OpenGL::IndexBuffer::finish()
{
	HAKO_ASSERT(this->init_called, "init() must be called first");
	// Do nothing.
}



#endif
