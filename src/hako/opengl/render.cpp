#ifdef HAKO_MODULE_OPENGL


#include "render.h"
#include "gl_includes.h"
#include "manager.h"
#include "commandlist.h"
#include "material.h"
#include "vertex.h"
#include <hako/common/debug.h>
#include <hako/engine/engine.h>
#include <math.h>


void Hako::OpenGL::render(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	glFinish();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Hako::OpenGL::Manager* gfx = engine->get_gfx();
    for (unsigned int i = 0; i < gfx->commandlists.get_length(); i++)
    {
		execute_commandlist(gfx->commandlists.get_element(i));
    }

	glFlush();

/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
	glViewport(0, 0, 640, 480);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(cosf(engine->get_fixed_milliseconds_since_startup() / 200.0f), 0.0, -3.0);
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0, 0.7, 0.1);
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, 1.0);
	glEnd();
*/
}



void Hako::OpenGL::execute_commandlist(Hako::OpenGL::CommandList* commandlist)
{
	Hako::OpenGL::Material* current_material = nullptr;

	//GLuint vertexArrayObject;
	//glGenVertexArrays(1, &vertexArrayObject);
	//glBindVertexArray(vertexArrayObject);

	for (unsigned int i = 0; i < commandlist->commands.get_length(); i++)
	{
		Hako::OpenGL::CommandList::Command* command = &commandlist->commands.get_element(i);

		switch (command->kind)
		{
			case Hako::OpenGL::CommandList::Command::Kind::SetMaterial:
			{
				current_material = command->command_data.material;
				glUseProgram(current_material->gl_program);
				break;
			}
			case Hako::OpenGL::CommandList::Command::Kind::SetVertexBuffer:
			{
				Hako::OpenGL::VertexBuffer* buffer = command->command_data.vertex_buffer;
				glEnableVertexAttribArray(current_material->attribute_slots.get_element(command->index));
				glBindBuffer(GL_ARRAY_BUFFER, buffer->gl_buffer);
				glVertexAttribPointer(current_material->attribute_slots.get_element(command->index), 3, GL_FLOAT, GL_TRUE, 0, (void*)0);
				break;
			}
			case Hako::OpenGL::CommandList::Command::Kind::DrawIndexed:
			{
				Hako::OpenGL::IndexBuffer* index_buffer = command->command_data.index_buffer;
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->gl_buffer);
				glDrawRangeElements(GL_TRIANGLES, 0, index_buffer->index_number, index_buffer->index_number, GL_UNSIGNED_INT, (void*)0);
				break;
			}
		}

		HAKO_OPENGL_CHECKERROR();
	}
}



#endif
