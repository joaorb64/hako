#ifndef HAKO_ENGINE_FILESYS_MANAGER_H
#define HAKO_ENGINE_FILESYS_MANAGER_H


namespace Hako
{
	class Engine;
	class String;


	namespace FileSys
	{
		class FileContents
		{
		public:
			unsigned char* data;
			unsigned int   length;
		};


		class Manager_Generic
		{
		public:
			virtual void init         (Hako::Engine* engine) = 0;
			virtual void shutdown     () = 0;

			virtual bool does_exist   (Hako::String* filename) = 0;
			virtual FileContents read (Hako::String* filename) = 0;
			virtual void free         (FileContents* contents) = 0;
		};
	}
}


#endif
