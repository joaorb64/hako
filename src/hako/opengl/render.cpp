#ifdef HAKO_BUILD_GFXOPENGL


#include "render.h"
#include "gl_includes.h"
#include "manager.h"
#include "commandlist.h"
#include "material.h"
#include "mesh.h"
#include <hako/common/debug.h>
#include <hako/engine/engine.h>
#include <math.h>


void Hako::OpenGL::render(Hako::Engine* engine)
{
	HAKO_UNUSED(engine);

	glFinish();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Hako::Gfx::Manager_OpenGL* gfx = (Hako::Gfx::Manager_OpenGL*)engine->get_gfx();
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



void Hako::OpenGL::execute_commandlist(Hako::Gfx::CommandList* cl)
{
	Hako::Gfx::CommandList_OpenGL* commandlist = (Hako::Gfx::CommandList_OpenGL*)cl;

	for (unsigned int i = 0; i < commandlist->commands.get_length(); i++)
	{
		Hako::Gfx::CommandList_OpenGL::Command* command = &commandlist->commands.get_element(i);

		switch (command->kind)
		{
			case Hako::Gfx::CommandList_OpenGL::Command::Kind::SetMaterial:
			{
				Hako::Gfx::Material_OpenGL* material = (Hako::Gfx::Material_OpenGL*)command->command_data.material;
				glUseProgram(material->gl_program);
				break;
			}
			case Hako::Gfx::CommandList_OpenGL::Command::Kind::Draw:
			{
				Hako::Gfx::Mesh_OpenGL* mesh = (Hako::Gfx::Mesh_OpenGL*)command->command_data.mesh;
				glBindVertexArray(mesh->gl_vertex_array_object);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->gl_index_buffer);
				glDrawRangeElements(GL_TRIANGLES, 0, mesh->index_number, mesh->index_number, GL_UNSIGNED_INT, (void*)0);
				break;
			}
		}

		HAKO_OPENGL_CHECKERROR();
	}
}



#endif
