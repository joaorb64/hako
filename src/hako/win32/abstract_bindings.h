#ifdef HAKO_BUILD_WIN32


#ifndef HAKO_WIN32_ABSTRACT_BINDINGS_H
#define HAKO_WIN32_ABSTRACT_BINDINGS_H


#ifdef HAKO_BUILD_GFXOPENGL
namespace Hako
{
	namespace OpenGL
	{
		class Manager;
		class Mesh;
		class Material;
		class CommandList;
	}


	namespace Gfx
	{
		typedef Hako::OpenGL::Manager      Manager;
		typedef Hako::OpenGL::Mesh         Mesh;
		typedef Hako::OpenGL::Material     Material;
		typedef Hako::OpenGL::CommandList  CommandList;
	}
}
#endif



namespace Hako
{
	namespace Win32
	{
		class Input_Manager;
	}

	namespace Standard
	{
		class Filesys_Manager;
	}

	namespace Input
	{
		typedef Hako::Win32::Input_Manager      Manager;
	}


	namespace FileSys
	{
		typedef Hako::Standard::Filesys_Manager Manager;
	}
}


#endif


#endif


