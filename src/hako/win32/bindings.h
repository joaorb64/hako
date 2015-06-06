#ifdef HAKO_BUILD_WIN32


#ifndef HAKO_WIN32_BINDINGS_H
#define HAKO_WIN32_BINDINGS_H



#ifdef HAKO_BUILD_GFXOPENGL
#include <hako/opengl/commandlist.h>
#include <hako/opengl/manager.h>
#include <hako/opengl/material.h>
#include <hako/opengl/mesh.h>
namespace Hako
{
	namespace Gfx
	{
		typedef Hako::Gfx::Manager_OpenGL      Manager;
		typedef Hako::Gfx::Mesh_OpenGL         Mesh;
		typedef Hako::Gfx::Material_OpenGL     Material;
		typedef Hako::Gfx::CommandList_OpenGL  CommandList;
	}
}
#endif


namespace Hako
{
	namespace Sfx
	{
		class Manager_Generic;

		typedef Hako::Sfx::Manager_Generic      Manager;
	}

	namespace Input
	{
		class Manager_Generic;

		typedef Hako::Input::Manager_Generic    Manager;
	}

	namespace FileSys
	{
		class Manager_Stdio;

		typedef Hako::FileSys::Manager_Stdio    Manager;
	}
}


#endif


#endif

