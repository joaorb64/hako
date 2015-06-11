#ifdef HAKO_PLATFORM_LINUX


#ifndef HAKO_LINUX_ABSTRACT_BINDINGS_H
#define HAKO_LINUX_ABSTRACT_BINDINGS_H


#ifdef HAKO_MODULE_OPENGL
namespace Hako
{
	namespace OpenGL
	{
		class Manager;
		class VertexBuffer;
		class IndexBuffer;
		class Material;
		class CommandList;
	}


	namespace Gfx
	{
		typedef Hako::OpenGL::Manager      Manager;
		typedef Hako::OpenGL::VertexBuffer VertexBuffer;
		typedef Hako::OpenGL::IndexBuffer  IndexBuffer;
		typedef Hako::OpenGL::Material     Material;
		typedef Hako::OpenGL::CommandList  CommandList;
	}
}
#endif



namespace Hako
{
	namespace Dummy
	{
		class Input_Manager;
	}

	namespace Standard
	{
		class Filesys_Manager;
	}


	namespace Input
	{
		typedef Hako::Dummy::Input_Manager      Manager;
	}


	namespace FileSys
	{
		typedef Hako::Standard::Filesys_Manager Manager;
	}
}


#endif


#endif


