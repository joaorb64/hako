#ifndef HAKO_ENGINE_FILESYS_FILESYS_H
#define HAKO_ENGINE_FILESYS_FILESYS_H


namespace Hako
{
	class Engine;
	class String;


	class FileSys
	{
	public:
		class FileContents
		{
		public:
			unsigned char* data;
			unsigned int   length;
		};


		virtual void init         (Hako::Engine* engine) = 0;
		virtual void shutdown     () = 0;

		virtual bool does_exist   (Hako::String* filename) = 0;
		virtual FileContents read (Hako::String* filename) = 0;
		virtual void free         (FileContents* contents) = 0;
	};
}


#endif
