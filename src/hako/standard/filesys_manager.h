#ifndef HAKO_STANDARD_FILESYS_MANAGER_H
#define HAKO_STANDARD_FILESYS_MANAGER_H


#include <hako/engine/filesys/filecontents.h>


namespace Hako
{
	class Engine;
	class String;


	namespace Standard
	{
		class Filesys_Manager
		{
		public:
			void init     (Hako::Engine* engine);
			void shutdown ();

			bool                        does_exist (Hako::String* filename);
			Hako::FileSys::FileContents read       (Hako::String* filename);
			void                        free       (Hako::FileSys::FileContents* contents);


		protected:
			Hako::Engine* engine;
		};
	}
}


#endif
