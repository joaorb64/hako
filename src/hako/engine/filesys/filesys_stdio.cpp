#include "filesys_stdio.h"
#include <hako/common/debug.h>
#include <hako/common/string.h>
#include <hako/engine/engine.h>
#include <stdio.h>


void Hako::FileSys_Stdio::init(Hako::Engine* engine)
{
	this->engine = engine;
}



void Hako::FileSys_Stdio::shutdown()
{
	/* Do nothing. */
}


bool Hako::FileSys_Stdio::does_exist(Hako::String* filename)
{
	FILE* fp = fopen(filename->get_c_str(), "rb");
	bool result = (fp != 0);
	if (fp)
		fclose(fp);
	return result;
}



Hako::FileSys::FileContents Hako::FileSys_Stdio::read(Hako::String* filename)
{
	//
	// Prepare a struct to return.
	//
	FileContents result;
	result.data   = nullptr;
	result.length = 0;

	//
	// Open the file.
	//
	FILE* fp = fopen(filename->get_c_str(), "rb");
	HAKO_ASSERT(fp, "could not open file");

	//
	// Figure out file size, then read entirely into memory.
	//
	fseek(fp, 0, SEEK_END);
	result.length = (unsigned int)ftell(fp);

	result.data = (unsigned char*)this->engine->get_mem_callbacks().alloc_callback.call(result.length + 1, 32);
	HAKO_ASSERT(result.data, "could not allocate memory for file contents");

	fseek(fp, 0, SEEK_SET);
	fread(result.data, 1, result.length, fp);

	//
	// Finally close the file, and add a trailing zero.
	//
	fclose(fp);
	result.data[result.length] = '\0';

	return result;
}



void Hako::FileSys_Stdio::free(Hako::FileSys::FileContents* contents)
{
	this->engine->get_mem_callbacks().free_callback.call(contents->data);
	contents->data = nullptr;
}
