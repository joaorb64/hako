#ifndef HAKO_ENGINE_FILESYS_FILESYS_STDIO_H
#define HAKO_ENGINE_FILESYS_FILESYS_STDIO_H


#include "filesys.h"


namespace Hako
{
	class Engine;
	class String;


	class FileSys_Stdio : public FileSys
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


#endif
