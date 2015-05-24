#ifndef HAKO_ENGINE_FILESYS_FILESYS_STDIO_H
#define HAKO_ENGINE_FILESYS_FILESYS_STDIO_H


#include "manager.h"


namespace Hako
{
	class Engine;
	class String;


	namespace FileSys
	{
		class Manager_Stdio : public Hako::FileSys::Manager_Generic
		{
		public:
			void init         (Hako::Engine* engine) override;
			void shutdown     () override;

			bool does_exist   (Hako::String* filename) override;
			FileContents read (Hako::String* filename) override;
			void free         (FileContents* contents) override;


		protected:
			Hako::Engine* engine;
		};
	}
}


#endif
