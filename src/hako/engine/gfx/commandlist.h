#ifndef HAKO_ENGINE_GFX_COMMANDLIST_H
#define HAKO_ENGINE_GFX_COMMANDLIST_H


#include <hako/engine/bindings.h>


namespace Hako
{
	namespace Gfx
	{
		class CommandList_Generic
		{
		public:
			~CommandList_Generic () { /* Do nothing. */ }
			void init            (Hako::Engine* engine) = 0;

            void begin           () = 0;
            void set_material    (Hako::Gfx::Material* material) = 0;
            void draw            (Hako::Gfx::Mesh* mesh) = 0;
            void finish          () = 0;
		};
	}
}


#endif




