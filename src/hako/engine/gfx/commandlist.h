#ifndef HAKO_ENGINE_GFX_COMMANDLIST_H
#define HAKO_ENGINE_GFX_COMMANDLIST_H


#include <hako/engine/abstract_bindings.h>


namespace Hako
{
	class Engine;


	namespace Gfx
	{
		class CommandList_Generic
		{
		public:
			virtual ~CommandList_Generic () { /* Do nothing. */ }
			virtual void init            (Hako::Engine* engine) = 0;
			virtual void clear           () = 0;

            virtual void begin           () = 0;
            virtual void set_material    (Hako::Gfx::Material_Generic* material) = 0;
            virtual void draw            (Hako::Gfx::Mesh_Generic* mesh) = 0;
            virtual void finish          () = 0;
		};
	}
}


#endif




