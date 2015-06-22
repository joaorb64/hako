#ifdef HAKO_MODULE_OPENGL


#ifndef HAKO_OPENGL_MANAGER_H
#define HAKO_OPENGL_MANAGER_H


#include <hako/engine/abstract_bindings.h>
#include <hako/common/ds/vector.h>


namespace Hako
{
	class Engine;


	namespace OpenGL
	{
		class Manager
		{
			friend class RenderManager;


		public:
			void init              (Hako::Engine* engine);

			void commandlist_clear ();
			void commandlist_add   (Hako::OpenGL::CommandList* commandlist);


		protected:
			Hako::DS::Vector<Hako::OpenGL::CommandList*> commandlists;
		};
	}
}


#endif


#endif

