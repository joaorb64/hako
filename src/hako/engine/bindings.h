#ifndef HAKO_ENGINE_BINDINGS_H
#define HAKO_ENGINE_BINDINGS_H


namespace Hako
{
	namespace Gfx
	{
		class Manager_Generic;
		class Mesh_Generic;
		class Material_Generic;
		class CommandList_Generic;

		typedef Hako::Gfx::Manager_Generic      Manager;
		typedef Hako::Gfx::Mesh_Generic         Mesh;
		typedef Hako::Gfx::Material_Generic     Material;
		typedef Hako::Gfx::CommandList_Generic  CommandList;
	}

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
		class Manager_Generic;

		typedef Hako::FileSys::Manager_Generic  Manager;
	}
}


#endif
